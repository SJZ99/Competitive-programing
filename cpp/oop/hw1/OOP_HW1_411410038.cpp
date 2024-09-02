#pragma GCC optimize("O3", "unroll-loops")

#define _ cin.tie(0) -> sync_with_stdio(false);

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;
using ll = long long int;

class PQubit;
class LQubit;
class QGate;

class QCircuit;
class QProcessor;

// ---------------- physical Qubit ----------------
class PQubit {
    int id, lid;
public:
    inline void setLQubit(const int& lqbid) {
        lid = lqbid;
    }

    inline int getLQubit() { return lid; }
};

// ---------------- Logical Qubit ----------------
class LQubit {
    int id, pid;

public: 
    LQubit(int id) : id(id) {}

    // set Logical qubit's location
    inline void setLocation(int pid) {
        this->pid = pid;
    }

    inline int getLocation() { return pid; }
};

// ---------------- QGate ----------------
class QGate {
    int id, lid1, lid2, precedence;

public:
    QGate() : id(0), lid1(0), lid2(0) {}

    QGate(int id, int id1, int id2) : id(id), lid1(id1), lid2(id2), precedence(-1) {}

    QGate(const QGate& gate) {
        id = gate.id;
        lid1 = gate.lid1;
        lid2 = gate.lid2;
        precedence = gate.precedence;
    }

    // precedence after topological sort
    inline void setPrecedence(const int& i) {
        precedence = i;
    }

    inline int getPrecedence() const { return precedence; }
    inline int getId() const { return id; }
    inline int getLId1() const { return lid1; }
    inline int getLId2() const { return lid2; }
};

// ---------------- QCircuit ----------------
class QCircuit {
    // number of gates
    int n;

    // all gates
    vector<QGate> gates;

    // for topology
    vector<int> indegree;
    vector<vector<int>> to;

    // sorted gates' id
    vector<int> operation;

    // iterator
    int curr = 0;

public: 
    QCircuit() {}

    // set number of gates
    inline void setGateNumber(const int& gateN) {
        gates.resize(gateN + 1);
        indegree.resize(gateN + 1);
        to.resize(gateN + 1);
        operation.resize(gateN + 1);
        n = gateN;
    }

    // add a new gate
    inline void addGate(const int& gateId, const int& lqbid1, const int& lqbid2) {
        gates[gateId] = QGate(gateId, lqbid1, lqbid2);
    }

    // add the order of two QGates
    inline void addEdge(const int& gate1, const int& gate2) {
        to[gate1].push_back(gate2);
        indegree[gate2]++;
    }

    // topological sort
    void sort();

    // get number of gates
    inline int getGateNumber() {
        return n;
    }

    inline const QGate* getNextOperation() {
        if(curr < n) {
            return &(gates[operation[curr]]);
        }
        return nullptr;
    }

    inline void finishOneGate() {
        if(curr < n) curr++;
    }

    inline void resetIterator() {
        curr = 0;
    }
};

void QCircuit::sort() {
    queue<int> nodes;
    vector<bool> isFinished(n);
    int cnt = 0;

    for(int i = 1; i <= n; ++i) {
        if(indegree[i] == 0) {
            nodes.push(i);
            gates[i].setPrecedence(0);
        }
    }

    while(!nodes.empty()) {
        int curr = nodes.front(); nodes.pop();
        int p = gates[curr].getPrecedence();

        isFinished[curr] = true;
        operation[cnt++] = curr;

        for(const int& neigh : to[curr]) {
            indegree[neigh]--;
            if(indegree[neigh] == 0) {
                nodes.push(neigh);
                gates[neigh].setPrecedence(p + 1);
            }
        }
    }
}

// ---------------- QProcessor ----------------
class QProcessor {
    // n of physical qubits and logical qubits
    int pn, ln;

    // physical qubits
    vector<PQubit> pqbs;
    
    // logical qubits
    vector<LQubit> lqbs;

    // adjecency list of physical qubits
    vector<set<int>> adj;

    // store best result
    int swapCnt = INT_MAX;
    vector<QGate> best;
    
    // for routing
    vector<int> path;
    inline int distanceBetween(const int& i, const int& j);

    inline void swapLQubit(const int& pid1, const int& pid2) {
        int lb1 = pqbs[pid1].getLQubit();
        int lb2 = pqbs[pid2].getLQubit();

        // set physical
        pqbs[pid1].setLQubit(lb2);
        pqbs[pid2].setLQubit(lb1);

        // set logical
        lqbs[lb1].setLocation(pid2);
        lqbs[lb2].setLocation(pid1);
    }

public:
    QProcessor() {}
    inline void setPQubitNumber(const int& n) {
        pqbs.resize(n + 1);
        adj.resize(n + 1);
        this->pn = n;
    }

    inline void setLQubitsNumber(const int& n) {
        lqbs.reserve(n + 1);
        for(int i = 1; i <= n; ++i) {
            lqbs[i] = LQubit(i);
        }
        ln = n;
    }

    inline void setMapping(const vector<int>& lqbOnWhere) {
        if((int) lqbOnWhere.size() < pn + 1) {
            cerr << "setMapping parameter error!\n";
        }

        for(int pid = 1, lid = 1; pid <= pn; ++pid) {
            lid = lqbOnWhere[pid];

            if(lid == -1) {
                pqbs[pid].setLQubit(-1);
                continue;
            }
            
            if(lid <= 0 || lid > ln) {
                cerr << "Wrong logical qubit id: " << lid << "\n";;
                return;
            }

            lqbs[lid].setLocation(pid);
            pqbs[pid].setLQubit(lid);
        }
    }

    inline void addEdge(const int& id1, const int& id2) {
        adj[id1].insert(id2);
        adj[id2].insert(id1);
    }

    inline void executeAndUpdateResult(QCircuit& circuit);

    inline const vector<QGate>& getResult() { return best; }
    inline int getSwap() { return swapCnt; }

    friend ostream& operator << (ostream& out, const QProcessor& processor);
};

int QProcessor::distanceBetween(const int& i, const int& j) {
    vector<int> from(pn + 1);
    from[i] = -1;
    vector<int> dis(pn + 1, -1);
    dis[i] = 0;
    queue<int> q;
    q.push(i);

    while(!q.empty()) {
        int node = q.front(); 
        q.pop();

        for(int nei : adj[node]) {
            if(dis[nei] == -1) {
                dis[nei] = dis[node] + 1;
                q.push(nei);
                from[nei] = node;

                if(j == nei) {
                    break;
                }
            }
        }

        if(dis[j] != -1) break;
    }

    path.clear();
    path.reserve(dis[j]);

    for(int pos = j; pos != -1; pos = from[pos]) {
        path.push_back(pos);
    }

    return dis[j];
}

ostream& operator << (ostream& out, const QProcessor& processor) {
    const vector<QGate>& best = processor.best;

    // out << processor.swapCnt << "\n";
    for(const QGate& g : best) {
        if(g.getId() == -1) {
            out << "SWAP q" << g.getLId1() << " q" << g.getLId2() << "\n"; 
        } else {
            out << "CNOT q" << g.getLId1() << " q" << g.getLId2() << "\n"; 
        }
    }
    return out;
}

void QProcessor::executeAndUpdateResult(QCircuit& circuit) {
    
    const QGate* gate;

    int id1, id2, d, swap = 0;
    vector<QGate> op;
    op.reserve(circuit.getGateNumber() * 3 / 2);
    while((gate = circuit.getNextOperation()) != nullptr) {

        id1 = lqbs[gate->getLId1()].getLocation(), id2 = lqbs[gate->getLId2()].getLocation();
        d = this->distanceBetween(id1, id2);

        // do it directly
        if(d == 1) {
            op.push_back(*gate);
            circuit.finishOneGate();
            continue;
        }

        // find path to change
        swap += d - 1;
        
        for(int i = path.size() - 1, pid1 = 0, pid2 = 0, len = 1; i > len; --i) {
            pid1 = path[i - 1], pid2 = path[i];
            swapLQubit(pid1, pid2);
            // fromMoveTo(pid2, pid1);
            op.push_back(QGate(-1, pqbs[pid1].getLQubit(), pqbs[pid2].getLQubit()));
        }
        // setTo(lid, path.back());
        op.push_back(*gate);

        circuit.finishOneGate();
    }

    if(swap < swapCnt) {
        best = op;
        swapCnt = swap;
    }

    circuit.resetIterator();
}

// ---------------- main ----------------
int lqbN, gateN, precedenceN, pqbN, plinks;
QCircuit circuit;
QProcessor processor;

inline void inputAndInitialize() {
    cin >> lqbN >> gateN >> precedenceN >> pqbN >> plinks;

    circuit.setGateNumber(gateN);
    processor.setPQubitNumber(pqbN);
    processor.setLQubitsNumber(lqbN);

    // gate input
    for(int i = 0, gateId, lqbId1, lqbId2; i < gateN; ++i) {
        cin >> gateId >> lqbId1 >> lqbId2;
        circuit.addGate(gateId, lqbId1, lqbId2);
    }

    // gate precedence input
    for(int i = 0, precedenceId, gate1, gate2; i < precedenceN; ++i) {
        cin >> precedenceId >> gate1 >> gate2;
        circuit.addEdge(gate1, gate2);
    }

    // physical link input
    for(int i = 0, linkId, id1, id2; i < plinks; ++i) {
        cin >> linkId >> id1 >> id2;
        processor.addEdge(id1, id2);
    }

    circuit.sort();
}

int main(void) { _

    inputAndInitialize();

    int minn = INT_MAX, minIndex = -1;

    // first try
    vector<vector<int>> mapping(3, vector<int>(pqbN + 1));

    // mapping 0
    for(int i = 1; i <= lqbN; ++i) {
        mapping[0][i] = i;
    }
    for(int i = lqbN + 1; i <= pqbN; ++i) {
        mapping[0][i] = -1;
    }

    // mapping 1
    for(int i = 1; i <= lqbN; ++i) {
        mapping[1][i] = lqbN - i + 1;
    }
    for(int i = lqbN + 1; i <= pqbN; ++i) {
        mapping[1][i] = -1;
    }

    // mapping 2
    int half = lqbN / 2;
    for(int i = 1; i <= half; ++i) {
        mapping[2][i] = half - i + 1;
    }
    for(int i = half+1; i <= lqbN; ++i) {
        mapping[2][i] = i;
    }
    for(int i = lqbN + 1; i <= pqbN; ++i) {
        mapping[2][i] = -1;
    }

    // execute mapping
    int tmp = 0;
    for(int i = 0; i < 3; ++i) {
        processor.setMapping(mapping[i]);
        processor.executeAndUpdateResult(circuit);
        tmp = processor.getSwap();
        if(tmp < minn) {
            minn = tmp;
            minIndex = i;
        }
    }
    
    // printf mapping
    for(int i = 1; i <= lqbN; ++i) {
        cout << i << " " << mapping[minIndex][i] << "\n";
    }

    // print result
    cout << processor;
    return 0;
}

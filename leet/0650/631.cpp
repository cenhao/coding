#include <bits/stdc++.h>
using namespace std;

class IObserver;

class IObservable {
public:
	virtual void AddObserver(IObserver *pobserver) = 0;
	virtual void RemoveObserver(IObserver *pobserver) = 0;
};

class IObserver {
public:
	virtual void Notify(int change) = 0;
};

class Cell : public IObservable, IObserver {
public:
	Cell() : value(0) {}
	Cell(const Cell &c) {
		value = c.value;
		m_observers = c.m_observers;
		m_observing = c.m_observing;
	}
	Cell(Cell &&mc) {
		m_observers = move(mc.m_observers);
		m_observing = move(mc.m_observing);
		value = mc.value;
	}
	void AddObserver(IObserver *pobserver) {
		m_observers.insert(pobserver);
	}
	void RemoveObserver(IObserver *pobserver) {
		m_observers.erase(pobserver);
	}
	void Notify(int change) {
		value += change;
		for (auto pobserver : m_observers) { pobserver->Notify(change); }
	}
	void Set(int v) {
		int change = v - value;
		for (auto pobserving : m_observing) {
			pobserving->RemoveObserver(this);
		}
		m_observing.clear();
		for (auto pobserver : m_observers) {
			pobserver->Notify(change);
		}
		value = v;
	}
	int Get() {
		return value;
	}
	void Sum(vector<Cell*> &pcells) {
		int backup = value;
		value = 0;
		for (auto pobserving : m_observing) { pobserving->RemoveObserver(this); }
		m_observing.clear();
		for (auto pcell : pcells) {
			pcell->AddObserver(this);
			m_observing.push_back(pcell);
			value += pcell->Get();
		}
		int change = value - backup;
		for (auto pobserver : m_observers) {
			pobserver->Notify(change);
		}
	}
private:
	multiset<IObserver*> m_observers;
	vector<IObservable*> m_observing;
	int value;
};

class Excel {
public:
	Excel(int H, char W) {
		int h = H, w = W - 'A' + 1;
		for (int i=0; i<h; ++i) {
			vector<Cell> row;
			for (int j=0; j<w; ++j) { row.push_back(Cell()); }
			m_matrix.push_back(move(row));
		}
	}

	void set(int r, char c, int v) {
		int rr = r - 1, cc = c - 'A';
		m_matrix[rr][cc].Set(v);
	}

	int get(int r, char c) {
		int rr = r - 1, cc = c - 'A';
		return m_matrix[rr][cc].Get();
	}

	int sum(int r, char c, vector<string> strs) {
		int rr = r - 1, cc = c - 'A';
		m_matrix[rr][cc].Set(0);
		vector<Cell*> pcells;
		for (auto &str : strs) {
			if (str.length() <= 2) {
				char tc;
				int tr;
				sscanf(str.c_str(), "%c%d", &tc, &tr);
				int trr = tr - 1, tcc = tc - 'A';
				pcells.push_back(&m_matrix[trr][tcc]);
			} else {
				char tsc, tec;
				int tsr, ter;
				sscanf(str.c_str(), "%c%d:%c%d", &tsc, &tsr, &tec, &ter);
				int srr = tsr - 1, scc = tsc - 'A';
				int err = ter - 1, ecc = tec - 'A';
				for (int i=srr; i<=err; ++i) {
					for (int j=scc; j<=ecc; ++j) {
						pcells.push_back(&m_matrix[i][j]);
					}
				}
			}
		}

		m_matrix[rr][cc].Sum(pcells);

		return m_matrix[rr][cc].Get();
	}
private:
	vector<vector<Cell>> m_matrix;
};

int main() {
	Excel obj(26, 'Z');
	obj.set(1, 'A', 1);
	obj.set(1, 'I', 1);
	vector<string> vstrs;
	string tmp = "A1:D6";
	vstrs.push_back(tmp);
	tmp = "A1:G3";
	vstrs.push_back(tmp);
	tmp = "A1:C12";
	vstrs.push_back(tmp);
	obj.sum(7, 'D', vstrs);
	vstrs.clear();
	tmp = "A1:D7";
	vstrs.push_back(tmp);
	tmp = "D1:F10";
	vstrs.push_back(tmp);
	tmp = "D3:I8";
	vstrs.push_back(tmp);
	tmp = "I1:I9";
	vstrs.push_back(tmp);
	cout << obj.sum(10, 'G', vstrs) << endl;
	//int param_2 = obj.get(2, 'B');
	//cout << param_2 << endl;
	return 0;
}

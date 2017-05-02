#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
char buff[MAXN+10];

class IContext {
public:
	virtual void add_tag(char c) = 0;
	virtual void add_color() = 0;
	virtual void next_state() = 0;
	virtual void set_close() = 0;
	virtual void handle(char c) = 0;
	virtual void get_cnt(int &r, int &y, int &b) = 0;
};

class AState {
public:
	virtual void handle(char c) = 0;
protected:
	IContext *m_pctx;
};

class NoOpState : public AState {
public:
	NoOpState(IContext *pctx) { m_pctx = pctx; }
	void handle(char c) final {
		// shouldn't be other state
		if (c == '<') { m_pctx->next_state(); }
	}
};

class TagState : public AState {
public:
	TagState(IContext *pctx) { m_pctx = pctx; }
	void handle(char c) final {
		if (c == '/') {
			// _ctx is not close
			m_pctx->set_close();
		} else if (c == '>') {
			m_pctx->next_state();
		} else {
			m_pctx->add_tag(c);
		}
	}
};

class ColoredState : public AState {
public:
	ColoredState(IContext *pctx) { m_pctx = pctx; }
	void handle(char c) final {
		if (c != '<') {
			if (c != ' ') { m_pctx->add_color(); }
		} else {
			m_pctx->next_state();
		}
	}
};

class Context : public IContext {
public:
	Context() {
		m_noop = new NoOpState(this);
		m_tag = new TagState(this);
		m_color = new ColoredState(this);
		m_cur = m_noop;
		m_is_close = false;
		m_cnt[0] = m_cnt[1] = m_cnt[2] = 0;
	}
	virtual ~Context() {
		if (m_noop != NULL) {
			delete m_noop;
			m_noop = NULL;
		}
		if (m_tag != NULL) {
			delete m_tag;
			m_tag = NULL;
		}
		if (m_color != NULL) {
			delete m_color;
			m_color = NULL;
		}
		m_cur = NULL;
	}
	void handle(char c) final {
		m_cur->handle(c);
	}
	void set_close() final {
		m_is_close = true;
	}
	void next_state() final {
		if (m_cur == m_noop) {
			m_cur = m_tag;
		} else if (m_cur == m_tag) {
			if (!m_is_close) {
				if (m_cbuff == "red") {
					m_st_idx.push(0);
				} else if (m_cbuff == "yellow") {
					m_st_idx.push(1);
				} else {
					m_st_idx.push(2);
				}
				m_cur = m_color;
			} else {
				// color should match
				m_st_idx.pop();
				m_cur = (m_st_idx.empty()) ? m_noop : m_cur = m_color;
			}
		} else {
			m_cur = m_tag;
		}

		m_cbuff = "";
		m_is_close = false;
	}
	void add_color() final {
		++m_cnt[m_st_idx.top()];
	}
	void add_tag(char c) final {
		m_cbuff += c;
	}
	void get_cnt(int &r, int &y, int &b) final {
		r = m_cnt[0]; y = m_cnt[1]; b = m_cnt[2];
	}
private:
	AState *m_noop;
	AState *m_tag;
	AState *m_color;
	AState *m_cur;
	bool m_is_close;
	string m_cbuff;
	stack<int> m_st_idx;
	int m_cnt[3];
};

int main() {
	fgets(buff, sizeof(buff), stdin);
	int len = strlen(buff);
	if (buff[len-1] == '\n') { buff[--len] = 0; }
	Context ctx;
	for (int i=0; i<len; ++i) {
		ctx.handle(buff[i]);
	}

	int r, y, b;
	ctx.get_cnt(r, y, b);
	printf("%d %d %d\n", r, y, b);
	return 0;
}

#ifndef __CONCURRENTLIST_H_
#define __CONCURRENTLIST_H_

#include <list>

namespace Base {
template<typename T>
class ConcurrentList {
public:
	typedef std::list<T> container_type;

public:
	ConcurrentList() {
	}

	void pop_front() {
		Base::AutoLock autoLock(m_mutex);
		if (!m_sequence.empty()) {
			m_sequence.pop_front();
		}
	}

	void pop() {
		pop_front();
	}

	void push_back(const T& v) {
		Base::AutoLock autoLock(m_mutex);
		m_sequence.push_back(v);
	}

	void push(const T& v) {
		push_back(v);
	}

	const T& front() const {
		Base::AutoLock autoLock(m_mutex);
		return m_sequence.front();
	}

	const T& back() const {
		Base::AutoLock autoLock(m_mutex);
		return m_sequence.back();
	}

	bool empty() const {
		Base::AutoLock autoLock(m_mutex);
		return m_sequence.empty();
	}

	/**
	 * low efficiency
	 * */
	typename container_type::size_type size() const {
		Base::AutoLock autoLock(m_mutex);
		return m_sequence.size();
	}

	/**
	 * thread safe foreach
	 * */
	bool nextAndPop(T& ref) {
		Base::AutoLock autoLock(m_mutex);
		if (!m_sequence.empty()) {
			ref = m_sequence.front();
			m_sequence.pop_front();
			return true;
		}
		return false;
	}

	/**
	 * will empty the this
	 * */
	bool dequeueAll(container_type& ref) {
		Base::AutoLock autoLock(m_mutex);
		if (!m_sequence.empty()) {
			ref.splice(ref.end(), m_sequence);
			return true;
		}
		return false;
	}

	/**
	 * will empty the ref
	 * */
	void enqueueAll(container_type& ref) {
		Base::AutoLock autoLock(m_mutex);
		m_sequence.splice(m_sequence.end(), ref);
	}

protected:
	container_type m_sequence;
	Base::ThreadMutex m_mutex;
};
}
#endif

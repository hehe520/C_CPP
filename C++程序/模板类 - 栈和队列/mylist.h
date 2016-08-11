/* -------------------------------------------
// 栈与队列头文件
//
// 类的关系图
//  list   list  node
//   |       \   /
//  stack    queue
//
// 提供模板类 stack<type> 和 queue<type>
// 模板类的定义和实现一定要在同一个文件里面
// 或者在类定义后面加上 #include <类实现.cpp>
--------------------------------------------- */

#pragma once	// 只编译一次

#ifndef LIST_H	// 如果没定义 LIST_H
#define LIST_H	// 定义一个	LIST_H

// 这里面的代码也编译一次

#endif			// 结束 #IF


// 抽象基类, 提供相同的接口
template <typename type>
class list
{
protected:
	virtual bool empty() = 0;
	virtual void push(type data) = 0;
	virtual void pop() = 0;
	virtual int  size() = 0;
};


// 队列和栈结点对象 []
template <typename type>
class node
{
public:
	type data;			// 数据域
	node<type> *next;	// 指针域
};


// 链式栈类, 保护继承后, 再公有化
template <typename type>
class stack: protected list<type>
{
public:
	stack();
	~stack();
	virtual bool empty();
	virtual void push(type data);
	virtual void pop();
	virtual int  size();
	type top();		// 取栈顶
private:
	int _size;
	node<type> *_top;	// type类型的结点结构地址
};


// 链式队列类,类似队列头结构
template <typename type>
class queue: protected list<type>
{
public:
	queue();
	~queue();
	virtual bool empty();
	virtual void push(type data);
	virtual void pop();
	virtual int  size();
	type front();		// 取队首
private:
	int qsize;
	node<type> *q_front;	// 头指针
	node<type> *q_rear;		// 尾指针
};


// -----------------队列实现部分---------------------

template <typename type>	// 构造函数
queue<type>::queue()
{
	node<type> *n;			// type 类型的node

	qsize = 0;
	n = new node<type>;		// 新建一个结点,连接头尾指针
	if (!n) abort();
	n->next = NULL;
	q_front = q_rear = n;
}

template <typename type>	// 析构函数
queue<type>::~queue()
{
	node<type> *cur;
	if (q_front)
	{
		cur = q_front;
		while (cur)
		{
			q_front = cur->next;
			delete cur;
			cur = q_front;
		}
	}
}

template <typename type>	// 判空
bool queue<type>::empty()
{
	if (q_front && q_front == q_rear) 
		return true;
	else return false;
}

// 创建时: [front == rear(空闲)]

// [front] -> [] -> ... -> [] -> [rear(空闲)]
// [] node 对象
template <typename type>	// 入队
void queue<type>::push(type data)
{
	node<type> *n;

	q_rear->data = data;
	n = new node<type>;		// 新增结点补上
	if (!n) abort();

	n->next = q_rear->next;	// 连进队列
	q_rear->next = n;
	q_rear = n;
	qsize++;
}

template <typename type>	// 出队
void queue<type>::pop()
{
	node<type> *cur;

	if (q_front && q_front != q_rear)
	{
		 cur = q_front;
		 q_front = cur->next;
		 delete cur;
		 qsize--;
	}
}

template <typename type>
int queue<type>::size()
{  return qsize;  }

template <typename type>
type queue<type>::front()
{
	if (q_front && q_front != q_rear)
		return q_front->data;
	else abort();
}


// -----------------栈实现部分---------------------
// 创建时 [top(空闲)]
// 使用后 [top(空闲)] -> [] -> [] -> NULL

template <typename type>	// 构造
stack<type>::stack()
{
	_top = new node<type>;
	_top->next = NULL;
	_size = 0;
}

template <typename type>	// 析构
stack<type>::~stack()
{
	node<type> *cur;
	cur = _top;
	while (cur)
	{
		_top = cur->next;
		delete cur;
		cur = _top;
	}
}

template <typename type>	// 入栈
void stack<type>::push(type data)
{
	node<type> *n;

	_top->data = data;		// 数据入栈
	n = new node<type>;		// 增减新空间
	if (!n) abort();
	n->next = _top;
	_top = n;
	_size++;
}

template <typename type>	// 出栈
void stack<type>::pop()
{
	node<type> *del;

	if (_size)
	{
		del = _top;		// 释放一个结点
		_top = _top->next;
		delete del;
		_size--;
	}
}

template <typename type>	// 取栈顶
type stack<type>::top()
{
	return _top->next->data;
}

template <typename type>	// 判空
bool stack<type>::empty()
{
	if (_size) return false;
	else return true;
}

template <typename type>	// 求大小
int stack<type>::size()
{  return _size; }
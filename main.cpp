#include <bits/stdc++.h>
using namespace std;

class LRU{
	list<int> deque;
	unordered_map<int,list<int>::iterator> map;
	int maxsize;
	
	
	
	public:
	
	LRU(int size)
	{
		maxsize=size;
	}
	
	void use(int element)
	{
		int size=deque.size();
		if(map.find(element)!=map.end())
		{
			auto position=map[element];
			deque.erase(position);
		}
		else
		{
			if(deque.size()==maxsize)
			{
				int lastelement = deque.back();
				deque.pop_back();
				map.erase(lastelement);
			}
		
		}
		
		deque.push_front(element);
		map[element]=deque.begin();
		
	}
	
	void display()
	{
		for(auto i=deque.begin();i!=deque.end();i++)
			cout<<*i<<" ";
		cout<<endl;
	}
	
};







int main() {
	
	LRU lru(5);
	
	lru.use(1);
	lru.use(2);
	lru.use(3);
	lru.use(4);
	lru.use(5);
	
	lru.display();
	
	lru.use(3);
	lru.display();
	lru.use(6);
	lru.display();
	
	
	return 0;
}
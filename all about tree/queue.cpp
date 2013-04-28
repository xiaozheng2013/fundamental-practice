#include "queue.h"
	void Queue::deQueue()
	{
		if(size == 0) 
		{
			cout<<"the queue is empty"<<endl;
			return;
		}
		
		else 
		{
			//items.erase(items.end() - 1);
			items.erase(items.begin());
			size--;
		}
	}



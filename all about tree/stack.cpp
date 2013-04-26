#include "stack.h"
	void Stack::pop()
	{
		if(size == 0) 
		{
			cout<<"the stack is empty"<<endl;
			return;
		}
		
		else 
		{
			//items.erase(items.end() - 1);
			items.erase(items.begin() + size - 1);
			size--;
		}
	}



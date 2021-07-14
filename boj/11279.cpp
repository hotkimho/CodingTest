#include <iostream>
#include <cstdio>
using namespace std;

class heap{
private:
	int arr[100002];
	int size;
	int top;
public:
	heap() {
		size = 0;
		top = 0;
	}
	void push(int data) {
		arr[++top] = data;
		size++;
		
		int child = top;
		int parent = child / 2;

		while ( child > 1 && arr[child] > arr[parent])
		{
			int tmp = arr[child];
			arr[child] = arr[parent];
			arr[parent] = tmp;

			child = parent;
			parent = child / 2;
		}
	}

	int pop() {

		if (size == 0)
			return 0;
		int result = arr[1];
		
		arr[1] = arr[top--];
		size--;
		int parent = 1;
		int child = 2;

		if (child + 1 <= top)
			child = (arr[child] > arr[child + 1]) ? child : child + 1;
		
		while (child <= top && arr[parent] < arr[child])
		{
			int tmp = arr[parent];
			arr[parent] = arr[child];
			arr[child] = tmp;

			parent = child;
			child = parent * 2;

			if (child + 1 <= top)
				child = (arr[child] > arr[child + 1]) ? child : child + 1;
		}
		return result;
	}
};
int main()
{
        heap h;
        int T;
        int num;
        cin>>T;
        for(int i=0; i<T; i++)
        {
                scanf("%d", &num);
                if ( num != 0)
                        h.push(num);
                else
                        printf("%d\n", h.pop());
        }
}

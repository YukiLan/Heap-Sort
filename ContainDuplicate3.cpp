#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	bool containDuplicate(vector<int>& nums)
	{
		int size = nums.size();
		if(size==1)
			return false;
		else
		{
			for(int i=size-1;i>=0;i--)
			{
				heapRebuild(nums,i,size);
			}
			int last=size-1;
			for(int i=1;i<size;i++,last--)
			{
				int temp = nums[0];
				nums[0]=nums[last];
				nums[last]=temp;
				heapRebuild(nums,0,last);
			}
			for(int i=0;i<size-1;i++)
			{
				if(nums[i]==nums[i+1])
				{
					return true;
					break;
				}
			}
			return false;
		}
	}
private:
	void heapRebuild(vector<int>& arr,int root, int size)
	{
		int child = 2*root+1;
		if(child <=size-1)
		{
			int rightChild = child+1;
			if(rightChild <= size-1)

				if(arr[child]>arr[rightChild])
					child = rightChild;
			if(arr[root]>arr[child])
			{
				int temp = arr[child];
				arr[child] = arr[root];
				arr[root]=temp;
				heapRebuild(arr,child,size);
			}
		}
	}
};

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(13);
	num.push_back(14);
	num.push_back(15);
	num.push_back(11);
	num.push_back(16);
	num.push_back(17);
	num.push_back(18);
	num.push_back(17);
	num.push_back(19);
	num.push_back(10);
	num.push_back(112);
	num.push_back(118);
	num.push_back(123);
	num.push_back(123);
	num.push_back(0);
	int size = num.size();

	Solution result;
	bool flag = result.containDuplicate(num);
	cout<<"original array arr :"<<endl;  
    for(int i=0;i<size;i++)  
        cout<<i+1<<" item is :"<<num[i]<<endl;  
    cout<<"after heap sorting  :"<<endl;  
    for(int i=0;i<size;i++)  
        cout<<i+1<<" item is :"<<num[i]<<endl;  
    if(flag==true)
    	cout<<"true"<<endl;
    else
    	cout<<"false"<<endl;
    return 0;  
}

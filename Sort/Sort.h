#include<iostream>
#include<assert.h>
using namespace std;

/***************************************************
***********************插入排序*********************
***************************************************/
void InsertSort(int *a,size_t n)
{
	assert(a);
	for(size_t i = 0;i < n-1;i++)//注意这里的边界控制，如果不是 n-1，就会出现越界
	{
		int end = i; //每一个有序区间的最后一个元素所在的位置为end
		int tmp = a[end+1]; //每次需要排序的元素先保存在tmp里面
		while(end >= 0)
		{
			if(a[end] > tmp)
			{
				a[end+1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end+1] = tmp;
	}
}
void PrintArray(int *a,size_t n)
{
	for(size_t i = 0;i < n;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void TestInsertSort()
{
	int a[] = {2,5,4,9,3,6,7,1,0,8};
	PrintArray(a,(sizeof(a)/sizeof a[0]));
	InsertSort(a,(sizeof(a)/sizeof a[0]));
	PrintArray(a,(sizeof(a)/sizeof a[0]));
}

/***************************************************
***********************希尔排序*********************
***************************************************/
void ShellSort(int *a,size_t n)
{
	assert(a);
	int gap = n;
	while(gap >
		1)
	{
		gap = gap/3+1; //控制分组
		for(size_t i = 0;i < n-gap;i++)//注意边界条件，避免越界
		{
			int end = i;
			int tmp = a[end+gap];
			while(end >= 0)
			{
				if(a[end] > tmp)
				{
					a[end+gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end+gap] = tmp;
		}
	}
}
void TestShellSort()
{
	int a[] = {2,5,4,9,3,6,7,1,0,8};
	PrintArray(a,(sizeof(a)/sizeof a[0]));
	InsertSort(a,(sizeof(a)/sizeof a[0]));
	PrintArray(a,(sizeof(a)/sizeof a[0]));
}

/***************************************************
***********************选择排序*********************
***************************************************/
void SelectSort(int *a,size_t n)
{
	assert(a);
	size_t left = 0,right = n-1;
	while(left < right)
	{
		size_t min = left,max = left;
		for(size_t i = left;i <= right;i++)
		{
			if(a[i] > a[max])
			{
				max = i;
			}
			if(a[i] < a[min])
			{
				min = i;
			}
		}
		swap(a[min],a[left]);
		if(max == left)
			max = min;
		swap(a[max],a[right]);
		--right;
		++left;
	}
}
void TestSelectSort()
{
	int a[] = {2,5,4,9,3,6,7,1,0,8};
	PrintArray(a,(sizeof(a)/sizeof a[0]));
	SelectSort(a,(sizeof(a)/sizeof a[0]));
	PrintArray(a,(sizeof(a)/sizeof a[0]));
}

/***************************************************
***********************堆排序*********************
***************************************************/
void AdjustDown(int *a,size_t root,size_t n)//向下调整算法
{
	size_t parent = root;
	size_t child = parent*2+1;//下标为0的为第一个孩子，所以parent*2+1为下标为左孩子
	while(child < n)
	{
		if(child+1 < n && a[child+1] > a[child])
		{
			++child;//让child指向较大的那个孩子
		}
		if(a[child] > a[parent])
		{
			swap(a[child],a[parent]);
			parent = child;
			child = child*2+1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int *a,size_t n)//升序，建大堆
{
	assert(a);
	int i;
	//从第一个非叶子节点开始，做向下调整，调整完第一个元素为最大元素
	for(i = (n-2)/2;i >= 0;--i)
	{
		AdjustDown(a,i,n);
	}//大堆建成
	int end;
	//交换第一个元素和最后一个元素，然后把交换后的第一个元素往下调整，再成大堆
	//--end，即是缩小范围，每次把最大的换到end的位置
	for(end = n-1;end >= 0;--end)
	{
		swap(a[end],a[0]);
		AdjustDown(a,0,end);
	}
}
void TestHeapSort()
{
	//int a[] = {10,3,5,8,2,6,4,9,1};
	int a[] = {2,1,8,9,3,7,5,6,4};
	PrintArray(a,(sizeof(a)/sizeof a[0]));
	HeapSort(a,(sizeof(a)/sizeof a[0]));
	PrintArray(a,(sizeof(a)/sizeof a[0]));
}
/***************************************************
***********************冒泡排序*********************
***************************************************/
void BubbleSort(int *a,size_t n)
{
	for(int end = n-1;end >= 0;--end)
	{
		bool exchang = false;    //优化不进行交换的
		for(int j = 0;j < end;++j)
		{
			if(a[j] > a[end])
			{
				swap(a[j],a[end]);
				exchang = true;
			}
		}
		if(exchang == false) //不需要进行优化
		{
			break;
		}
	}
}
void TestBubbleSort()
{
	int a[] = {2,5,4,9,3,6,7,1,0,8};
	PrintArray(a,(sizeof(a)/sizeof a[0]));
	BubbleSort(a,(sizeof(a)/sizeof a[0]));
	PrintArray(a,(sizeof(a)/sizeof a[0]));
}
/***************************************************
***********************快速排序*********************
***************************************************/
int GetMidIndex(int *a,int left,int right)
{
	int mid = left+((right-left)>>1);
	// left  mid  right
	if(a[left] < a[mid])
	{
		if(a[mid] < a[right])
			return mid;
		else if(a[right] < a[left])
			return left;
		else
			return right;
	}
	else //a[left] > a[mid]
	{
		if(a[right] < a[mid])
			return mid;
		else if(a[right] > a[left])
			return left;
		else
			return right;
	}
}
//1.左右指针法
int PartSort1(int *a,int left,int right)
{
	int& key = a[right]; //此处必须用引用才能达到后面用key作为交换值的效果
	int begin = left;
	int end = right;
	while(begin < end)
	{
		while(begin < end && a[begin] <= key)//特别需要注意边界条件
			++begin;
		while(begin < end && a[end] >= key)
			--end;
		//走到此处，begin所指向的值比key大，end所指向的值比key小
		if(begin < end)
			swap(a[begin],a[end]);
	}
	//走到此处，begin和end相遇
	swap(a[begin],key);//上面的key需要加上引用
	return begin;
}
//挖坑法
int PartSort2(int *a,int left,int right)
{
	int begin = left;
	int end = right;
	int key = a[end];
	int dig = right; //标记当前坑的位置
	while(begin < end)
	{
		while(begin < end && a[begin] <= key)
			++begin;
		if(begin < end)
		{
			a[dig] = a[begin];
			dig = begin;
		}
		while(begin < end && a[end] >= key)
			--end;
		if(begin < end)
		{
			a[dig] = a[end];
			dig = end;
		}
	}
	a[dig] = key;
	return dig;
}
//前后指针法

//选出key，若a[cur]<key,prev++;cur继续往后走，
//若a[cur]>key,prev不动，cur继续往后走，
//若再次遇到a[cur]<key,prev++;此时的cur和prev已经不指向同一个位置了，
//交换prev和cur所对应的值。
int PartSort3(int *a,int left,int right)
{
	int cur = left;
	int prev = left-1;
	int& key = a[right];
	while(cur < right)
	{
		//prev == cur时，其实也要交换的，不过此时它俩是指向同一个值
		if(a[cur] < key && ++prev != cur)
		{
			swap(a[prev],a[cur]);
		}
		++cur;//不管怎样，cur都要往后走
	}
	//cur走到了key所在的位置了
	swap(a[++prev],key);
	return prev;
}
void QuickSort(int *a,int left,int right)
{
	assert(a);
	if(left >= right)
		return;
	//当区间比较小时，用插入排序以优化程序
	//if(right - left < 5)
	//{
	//	InsertSort(a,right-left+1);
	//}
	else
	{
		int div = PartSort3(a,left,right);//分区间
		//[left,div-1]  [div+1,right]
		QuickSort(a,left,div-1);//递归子问题
		QuickSort(a,div+1,right);
	}
}
//递归转化为非递归，借用栈先进后出的性质来实现
#include<stack>
void QuickSortNonR(int *a,int left,int right)
{
	assert(a);
	stack<int> s;
	if(left < right)
	{
		s.push(right);//先进去的后出来
		s.push(left);
	}
	while(!s.empty())
	{
		int begin = s.top(); //left
		s.pop();
		int end = s.top();  //right
		s.pop();

		int div = PartSort1(a,begin,end);
		// [begin,div-1]  [div+1,end]
		if(begin < div-1)
		{
			s.push(div-1);
			s.push(begin);
		}
		if(div+1 < end)
		{
			s.push(end);
			s.push(div+1);
		}
	}
}
void TestQuickSort()
{
	int a[] = {2,5,4,9,3,6,7,1,0,8};
	PrintArray(a,(sizeof(a)/sizeof a[0]));
	QuickSortNonR(a,0,sizeof(a)/sizeof(a[0])-1);
	PrintArray(a,(sizeof(a)/sizeof a[0]));
}


/***************************************************
***********************归并排序*********************
***************************************************/void _MergeSort(int *a,int left,int right,int *tmp)
{
	if(left >= right)
		return;
	//找到中间位置
	int mid = left+((right-left)>>1);
	//递归子问题
	_MergeSort(a,left,mid,tmp);
	_MergeSort(a,mid+1,right,tmp);
	//进行归并
	size_t begin1 = left,end1 = mid;
	size_t begin2 = mid+1,end2 = right;
	size_t pos = begin1;
	size_t index = begin1; //tmp数组的下标
	while(begin1 <= end1 && begin2 <= end2)
	{
		if(a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else //a[begin2] < a[begin1]
			tmp[index++] = a[begin2++];
	}
	//拷贝没有拷完的数组的数据
	while(begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while(begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//把tmp数组的数据拷贝到a数组中去
	memcpy(a+pos,tmp+pos,sizeof(int)*(end2-pos+1)); //???????
}
void MergeSort(int *a,size_t n)
{
	assert(a);
	int * tmp = new int[n]; //自己申请空间
	_MergeSort(a,0,n-1,tmp);
	delete [] tmp; //自己释放空间
}
void TestMergeSort()
{
	int a[] = {2,5,4,9,3,6,7,1,0,8};
	PrintArray(a,(sizeof(a)/sizeof a[0]));
	MergeSort(a,sizeof(a)/sizeof(a[0]));
	PrintArray(a,(sizeof(a)/sizeof a[0]));
}


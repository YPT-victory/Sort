#include<iostream>
#include<assert.h>
using namespace std;

/***************************************************
***********************��������*********************
***************************************************/
void InsertSort(int *a,size_t n)
{
	assert(a);
	for(size_t i = 0;i < n-1;i++)//ע������ı߽���ƣ�������� n-1���ͻ����Խ��
	{
		int end = i; //ÿһ��������������һ��Ԫ�����ڵ�λ��Ϊend
		int tmp = a[end+1]; //ÿ����Ҫ�����Ԫ���ȱ�����tmp����
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
***********************ϣ������*********************
***************************************************/
void ShellSort(int *a,size_t n)
{
	assert(a);
	int gap = n;
	while(gap >
		1)
	{
		gap = gap/3+1; //���Ʒ���
		for(size_t i = 0;i < n-gap;i++)//ע��߽�����������Խ��
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
***********************ѡ������*********************
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
***********************������*********************
***************************************************/
void AdjustDown(int *a,size_t root,size_t n)//���µ����㷨
{
	size_t parent = root;
	size_t child = parent*2+1;//�±�Ϊ0��Ϊ��һ�����ӣ�����parent*2+1Ϊ�±�Ϊ����
	while(child < n)
	{
		if(child+1 < n && a[child+1] > a[child])
		{
			++child;//��childָ��ϴ���Ǹ�����
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
void HeapSort(int *a,size_t n)//���򣬽����
{
	assert(a);
	int i;
	//�ӵ�һ����Ҷ�ӽڵ㿪ʼ�������µ������������һ��Ԫ��Ϊ���Ԫ��
	for(i = (n-2)/2;i >= 0;--i)
	{
		AdjustDown(a,i,n);
	}//��ѽ���
	int end;
	//������һ��Ԫ�غ����һ��Ԫ�أ�Ȼ��ѽ�����ĵ�һ��Ԫ�����µ������ٳɴ��
	//--end��������С��Χ��ÿ�ΰ����Ļ���end��λ��
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
***********************ð������*********************
***************************************************/
void BubbleSort(int *a,size_t n)
{
	for(int end = n-1;end >= 0;--end)
	{
		bool exchang = false;    //�Ż������н�����
		for(int j = 0;j < end;++j)
		{
			if(a[j] > a[end])
			{
				swap(a[j],a[end]);
				exchang = true;
			}
		}
		if(exchang == false) //����Ҫ�����Ż�
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
***********************��������*********************
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
//1.����ָ�뷨
int PartSort1(int *a,int left,int right)
{
	int& key = a[right]; //�˴����������ò��ܴﵽ������key��Ϊ����ֵ��Ч��
	int begin = left;
	int end = right;
	while(begin < end)
	{
		while(begin < end && a[begin] <= key)//�ر���Ҫע��߽�����
			++begin;
		while(begin < end && a[end] >= key)
			--end;
		//�ߵ��˴���begin��ָ���ֵ��key��end��ָ���ֵ��keyС
		if(begin < end)
			swap(a[begin],a[end]);
	}
	//�ߵ��˴���begin��end����
	swap(a[begin],key);//�����key��Ҫ��������
	return begin;
}
//�ڿӷ�
int PartSort2(int *a,int left,int right)
{
	int begin = left;
	int end = right;
	int key = a[end];
	int dig = right; //��ǵ�ǰ�ӵ�λ��
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
//ǰ��ָ�뷨

//ѡ��key����a[cur]<key,prev++;cur���������ߣ�
//��a[cur]>key,prev������cur���������ߣ�
//���ٴ�����a[cur]<key,prev++;��ʱ��cur��prev�Ѿ���ָ��ͬһ��λ���ˣ�
//����prev��cur����Ӧ��ֵ��
int PartSort3(int *a,int left,int right)
{
	int cur = left;
	int prev = left-1;
	int& key = a[right];
	while(cur < right)
	{
		//prev == curʱ����ʵҲҪ�����ģ�������ʱ������ָ��ͬһ��ֵ
		if(a[cur] < key && ++prev != cur)
		{
			swap(a[prev],a[cur]);
		}
		++cur;//����������cur��Ҫ������
	}
	//cur�ߵ���key���ڵ�λ����
	swap(a[++prev],key);
	return prev;
}
void QuickSort(int *a,int left,int right)
{
	assert(a);
	if(left >= right)
		return;
	//������Ƚ�Сʱ���ò����������Ż�����
	//if(right - left < 5)
	//{
	//	InsertSort(a,right-left+1);
	//}
	else
	{
		int div = PartSort3(a,left,right);//������
		//[left,div-1]  [div+1,right]
		QuickSort(a,left,div-1);//�ݹ�������
		QuickSort(a,div+1,right);
	}
}
//�ݹ�ת��Ϊ�ǵݹ飬����ջ�Ƚ������������ʵ��
#include<stack>
void QuickSortNonR(int *a,int left,int right)
{
	assert(a);
	stack<int> s;
	if(left < right)
	{
		s.push(right);//�Ƚ�ȥ�ĺ����
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
***********************�鲢����*********************
***************************************************/void _MergeSort(int *a,int left,int right,int *tmp)
{
	if(left >= right)
		return;
	//�ҵ��м�λ��
	int mid = left+((right-left)>>1);
	//�ݹ�������
	_MergeSort(a,left,mid,tmp);
	_MergeSort(a,mid+1,right,tmp);
	//���й鲢
	size_t begin1 = left,end1 = mid;
	size_t begin2 = mid+1,end2 = right;
	size_t pos = begin1;
	size_t index = begin1; //tmp������±�
	while(begin1 <= end1 && begin2 <= end2)
	{
		if(a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else //a[begin2] < a[begin1]
			tmp[index++] = a[begin2++];
	}
	//����û�п�������������
	while(begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while(begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//��tmp��������ݿ�����a������ȥ
	memcpy(a+pos,tmp+pos,sizeof(int)*(end2-pos+1)); //???????
}
void MergeSort(int *a,size_t n)
{
	assert(a);
	int * tmp = new int[n]; //�Լ�����ռ�
	_MergeSort(a,0,n-1,tmp);
	delete [] tmp; //�Լ��ͷſռ�
}
void TestMergeSort()
{
	int a[] = {2,5,4,9,3,6,7,1,0,8};
	PrintArray(a,(sizeof(a)/sizeof a[0]));
	MergeSort(a,sizeof(a)/sizeof(a[0]));
	PrintArray(a,(sizeof(a)/sizeof a[0]));
}


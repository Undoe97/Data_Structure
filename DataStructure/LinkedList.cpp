#include "LinkedList.h"

// ��� ����
Node* SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = new Node;

	NewNode->Data = NewData; // �����͸� �����Ѵ�
	NewNode->NextNode = nullptr; // ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ�Ѵ�

	return NewNode; // ����� �ּҸ� ��ȯ�Ѵ�
}

// ��� �Ҹ�
void SLL_DestroyNode(Node* Node)
{
	delete Node;
}

// ��� �߰�
void SLL_AppendNode(Node*& Head, Node* NewNode)
{
	// ��� ��尡 NULL�̶�� ���ο� ��尡 Head�� �ȴ�
	if (Head == nullptr)
	{
		Head = NewNode;
	}
	else
	{
		// ������ ã�� NewNode�� �����Ѵ�
		Node* Tail = Head;
		while (Tail->NextNode != nullptr)
		{
			Tail = Tail->NextNode;
		}
		
		Tail->NextNode = NewNode;
	}
}

// ��� ����
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

// Head�� ���ο� ��� ����
void SLL_InsertHead(Node*& Head, Node* NewHead)
{
	if (Head == nullptr)
	{
		Head = NewHead;
	}
	else
	{
		NewHead->NextNode = Head;
		Head = NewHead;
	}
}

// ��� ����
void SLL_RemoveNode(Node*& Head, Node* Remove)
{
	if (Head == Remove)
	{
		Head = Remove->NextNode;
	}
	else
	{
		Node* Current = Head;
		while (Current != nullptr && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		if(Current != nullptr)
			Current->NextNode = Remove->NextNode;
	}
}

// ��� Ž��
Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != nullptr && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// ��� ���� ����
int SLL_GetNodeCount(Node* Head)
{
	int Count = 0;
	Node* Current = Head;

	while (Current != nullptr)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}
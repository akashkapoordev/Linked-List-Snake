#pragma once
#include "LinkListLib/Node.h"
namespace LinkListLib
{
	namespace DoubleLinkList
	{
		struct DoubleNode : public Node
		{
			Node* previous = nullptr;
		};
	}
}
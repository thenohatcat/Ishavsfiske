//Version: 0.1.2
//Author: Jakob Pipping
//Contributors:

#ifndef INC_ICEBERG_H
#define INC_ICEBERG_H

#ifdef ISHAV_0_1_2

#include <Angler\Node.h>

namespace Ishavsfiske
{
	class Iceberg
		: public Angler::Node
	{
	public:
		Iceberg();
	};
}

#else
#error Iceberg.h: Wrong version 0.1.2
#endif

#endif
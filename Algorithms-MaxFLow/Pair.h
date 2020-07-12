#ifndef __Pair_H
#define __Pair_H


struct Pair
{
	public:

		int m_Data;
		int m_Key;

		Pair(int data, int key)
		{
			m_Data = data;
			m_Key = key;
		}
};

#endif


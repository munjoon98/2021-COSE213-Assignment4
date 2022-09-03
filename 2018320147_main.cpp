/**
* Assignment 4 for COSE213 Data Structures
*
* Won-Ki Jeong (wkjeong@korea.ac.kr)
*
* 2021. 6. 1
*
*/

#include "LinkedBinaryTree.h"
#include "SearchTree.h" 
#include "AVLTree.h"

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */

#include <iostream>

using namespace std;

int main()
{
	typedef Entry<int, float> EntryType;

	LinkedBinaryTree<EntryType> t;

	std::cout << "Size : " << t.size() << std::endl;

	t.addRoot();

	std::cout << "Size : " << t.size() << std::endl;


	//
	//
	//
	SearchTree<EntryType>	st;

	std::cout << "Size : " << st.size() << std::endl;
	st.insert(1, 2.5);
	st.insert(3, 4.5);
	st.insert(7, 5.5);
	st.insert(2, 1.5);
	st.insert(3, 8.5);
	std::cout << "Size : " << st.size() << std::endl;

	for (SearchTree<EntryType>::Iterator it = st.begin(); it != st.end(); ++it)
	{
		std::cout << (*it).key() << " , " << (*it).value() << std::endl;
	}

	st.erase(3);
	std::cout << "Size : " << st.size() << std::endl;
	for (SearchTree<EntryType>::Iterator it = st.begin(); it != st.end(); ++it)
	{
		std::cout << (*it).key() << " , " << (*it).value() << std::endl;
	}

	std::cout << "------------" << std::endl;




	AVLTree<EntryType>	ste;

	std::cout << "Size : " << ste.size() << std::endl;
	ste.insert(1, 2.5); 
	ste.insert(4, 2.5);
	ste.insert(3, 4.5);
	ste.insert(7, 5.5);
	ste.insert(2, 1.5);
	ste.insert(3, 8.5);
	ste.insert(10, 4.5);
	ste.insert(15, 4.5);
	ste.insert(14, 4.5);
	ste.insert(12, 4.5);
	ste.insert(13, 4.5);
	ste.insert(22, 4.5);
	std::cout << "Size : " << ste.size() << std::endl;

	for (AVLTree<EntryType>::Iterator it = ste.begin(); it != ste.end(); ++it)
	{
		std::cout << (*it).key() << " , " << (*it).value() << std::endl;
	}

	ste.erase(3);
	std::cout << "Size : " << ste.size() << std::endl;
	for (AVLTree<EntryType>::Iterator it = ste.begin(); it != ste.end(); ++it)
	{
		std::cout << (*it).key() << " , " << (*it).value() << std::endl;
	}

	std::cout << "------------" << std::endl;
	//
	//
	//
	
	
	SearchTree<EntryType> se;
	// random test
	int nElem = 100; //100000000;

	int *key = new int[nElem * 2];
	float *val = new float[nElem * 2];

	std::srand(std::time(0)); // use current time as seed for random generator


							  // initialize
	for (int i = 0; i<nElem * 2; i++)
	{
		key[i] = std::rand();
		val[i] = (float)std::rand() / RAND_MAX * 20000;
	}

	//
	// Search tree Insert test
	//	
	clock_t dm;
	dm = clock();
	for (int i = 0; i<nElem; i++)
	{
		se.insert(key[i], val[i]);
	}
	dm = clock() - dm;
	printf("SearchTree Insert : It took me %f seconds.\n", ((float)dm) / (float)CLOCKS_PER_SEC);


	//
	// Search tree Find test
	//	
	dm = clock();
	for (int i = nElem; i<nElem * 2; i++)
	{
		se.find(key[i]);
	}
	dm = clock() - dm;
	printf("SearchTree Find : It took me %f seconds.\n", ((float)dm) / (float)CLOCKS_PER_SEC);

	//Search tree erase and find test

	dm = clock();
	for (int i = 0; i<nElem * 2; i++)
	{
		int ra = std::rand() % 100;
		if(ra<=19) se.find(key[i]);
		else se.erase(key[i]);
	}
	dm = clock() - dm;
	printf("SearchTree Erase and Find : It took me %f seconds.\n", ((float)dm) / (float)CLOCKS_PER_SEC);


	AVLTree<EntryType>	avl;
	//
	// AVL tree Insert test
	//	

	dm = clock();
	for (int i = 0; i<nElem; i++)
	{
		avl.insert(key[i], val[i]);
	}
	dm = clock() - dm;
	printf("AVLTree Insert : It took me %f seconds.\n", ((float)dm) / (float)CLOCKS_PER_SEC);


	//
	// AVL tree Find test
	//	
	dm = clock();
	for (int i = nElem; i<nElem * 2; i++)
	{
		avl.find(key[i]);
	}
	dm = clock() - dm;
	printf("AVLTree Find : It took me %f seconds.\n", ((float)dm) / (float)CLOCKS_PER_SEC);


	//AVLtree erase and find test
	dm = clock();
	for (int i = 0; i<nElem * 2; i++)
	{
		int ra = std::rand() % 100;
		if (ra <= 19) se.find(key[i]);
		else se.erase(key[i]);
	}
	dm = clock() - dm;
	printf("AVLTree Erase and Find : It took me %f seconds.\n", ((float)dm) / (float)CLOCKS_PER_SEC);



	return 0;
}
//
// Implementation
//
#include<algorithm>

template <typename E>					// constructor
  AVLTree<E>::AVLTree() : ST() { }

template<typename E>
inline AVLTree<E>::~AVLTree()
{
}

template <typename E>					// node height utility
  int AVLTree<E>::height(const TPos& v) const
    { return (v.isExternal() ? 0 : (*v).height()); }

template <typename E>					// set height utility
  void AVLTree<E>::setHeight(TPos v) {
    int hl = height(v.left());
    int hr = height(v.right());
    (*v).setHeight(1 + std::max(hl, hr));			// max of left & right
  }

template <typename E>					// is v balanced?
  bool AVLTree<E>::isBalanced(const TPos& v) const {	
    int bal = height(v.left()) - height(v.right());
    return ((-1 <= bal) && (bal <= 1));
  }

template <typename E>					// get tallest grandchild
  typename AVLTree<E>::TPos AVLTree<E>::tallGrandchild(const TPos& z) const {
    TPos zl = z.left();
    TPos zr = z.right();
    if (height(zl) >= height(zr))			// left child taller
      if (height(zl.left()) >= height(zl.right()))
        return zl.left();
      else
        return zl.right();
    else 						// right child taller
      if (height(zr.right()) >= height(zr.left()))
        return zr.right();
      else
        return zr.left();
  }


//
// ToDo
//

template <typename E>					// remove key k entry
  void AVLTree<E>::erase(const K& k) {
    
    // ToDo
    	TPos v = this->finder(k, ST::root());
	if (v.isExternal()) std::cout << "Erase of nonexistent\n";
	else {
		TPos w = this->eraser(v);
		rebalance(w);
	}
  }

template <typename E>					// insert (k,x)
  typename AVLTree<E>::Iterator AVLTree<E>::insert(const K& k, const V& x) {
    
    // ToDo
    	TPos v = this->inserter(k, x);
	setHeight(v);
	rebalance(v);
	return Iterator(v);
  }
  
template <typename E>					// rebalancing utility
  void AVLTree<E>::rebalance(const TPos& v) {
    
    // ToDo
    	TPos z = v;
	while ((z.v->par->par)) {
		z = z.parent();
		setHeight(z);
		if (!isBalanced(z)) {
			TPos x = tallGrandchild(z);
			z = restructure(x);
			setHeight(z.left());
			setHeight(z.right());
			setHeight(z);
		}
	}
  }

template <typename E>				// Binary Search Tree Rotation
  typename AVLTree<E>::TPos AVLTree<E>::restructure(const TPos& v) {

	// ToDo
	TPos w = v.parent();
	TPos q = w.parent();
	if (q.left() == w && w.left() == v) {
		TPos temp = w;
		temp.v->par = q.v->par;
		if (q.v->par->left == q.v) q.v->par->left = temp.v;
		else if (q.v->par->right == q.v) q.v->par->right = temp.v;
		q.v->left = temp.v->right;
		q.v->left->par = q.v;
		temp.v->right = q.v;
		q.v->par = temp.v;
		q = temp;
		return q;
	}
	else if (q.right() == w && w.right() == v) {
		TPos temp = w;
		temp.v->par = q.v->par;
		if (q.v->par->left == q.v) q.v->par->left = temp.v;
		else if (q.v->par->right == q.v) q.v->par->right = temp.v;
		q.v->right=temp.v->left;
		q.v->right->par = q.v;
		temp.v->left = q.v;
		q.v->par = temp.v;
		q=temp;
		return q;
	}
	else if (q.left() == w && w.right() == v) {
		TPos temp = v;
		temp.v->par = w.v->par;
		if (w.v->par->left == w.v) w.v->par->left = temp.v;
		else if (w.v->par->right == w.v) w.v->par->right = temp.v;
		w.v->right = temp.v->left;
		w.v->right->par = w.v;
		temp.v->left = w.v;
		w.v->par = temp.v;
	
		temp.v->par = q.v->par;
		if (q.v->par->left == q.v) q.v->par->left = temp.v;
		else if (q.v->par->right == q.v) q.v->par->right = temp.v;
		q.v->left = temp.v->right;
		q.v->left->par = q.v;
		temp.v->right = q.v;
		q.v->par = temp.v;
		q = temp;
		return q;
	}
	else if (q.right() == w && w.left() == v) {
		TPos temp = v;
		temp.v->par = w.v->par;
		if (w.v->par->left == w.v) w.v->par->left = temp.v;
		else if (w.v->par->right == w.v) w.v->par->right = temp.v;
		w.v->left = temp.v->right;
		w.v->left->par = w.v;
		temp.v->right = w.v;
		w.v->par = temp.v;
		temp.v->par = q.v->par;
		if (q.v->par->left == q.v) q.v->par->left = temp.v;
		else if (q.v->par->right == q.v) q.v->par->right = temp.v;
		q.v->right = temp.v->left;
		q.v->right->par = q.v;
		temp.v->left = q.v;
		q.v->par = temp.v;
		q = temp;
		return q;
	}
  }


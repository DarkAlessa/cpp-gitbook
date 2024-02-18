// C Structure & Typdef

struct name_ {...};

Ex.1
struct Ex {
	int n;
	int m;
};

struct Ex vl; // C standard
Ex vl;	  // C++
vl.n = 10;
vl.m = 20;
-------------------------------------------------
Ex.2
struct Ex {
	int n;
	int m;
} vl;

vl.n = 10;
vl.m = 20;
-------------------------------------------------

Ex.3
struct Ex {
   union { // anonymous union
      struct { int i, j; }; // anonymous structure
      struct { long k, l; } w;
   };
   int m;
} v1;
 
v1.i = 2;   // valid
v1.k = 3;   // invalid: inner structure is not anonymous
v1.w.k = 5; // valid
-------------------------------------------------

Ex.4 
struct Point {
	double x;
	double y;
	double z;
} p = {1.2, 1.3, 1.4}; // p.x=1.2, p.y=1.3, p.z=1.4
--------------------------------------------------
struct Point {
	double x;
	double y;
	double z;
};

struct Point p = {1.2, 1.3, 1.4}; // p.x=1.2, p.y=1.3, p.z=1.4
-------------------------------------------------

struct Y;	// Forward declaration
struct Y {...};

-------------------------------------------------

// Typedef Struct

typedef struct tnode tnode; // tnode in ordinary name space
                            // is an alias to tnode in tag name space
struct tnode {
    int count;
    tnode *left, *right; // same as struct tnode *left, *right;
}; // now tnode is also a complete type
tnode s, *sp; // same as struct tnode s, *sp;

--------------------------------------------------

typedef struct S { 
    int x; 
} S;

// OR
struct S { 
    int x; 
};

typedef struct S S;
---------------------------------------------------------------------
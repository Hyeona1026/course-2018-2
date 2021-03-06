#ifdef ___IntSet
#define ___IntSet

typedef struct {
	int max;
	int num;
	int *set;
}IntSet;

int Initialize(IntSet *s, int max);

int IsMember(const IntSet *s, int n);

void Add(IntSet *s, int n);

void Remove(IntSet *s, int n);

int Capacity(const IntSet *s);


int Size(const IntSet *s);

void Assign(IntSet *s1, const IntSet *s2);

int Equal(const IntSet *s1, const IntSet * 2);

IntSet *Union(IntSet *s1, const IntSet *s2, const IntSet *s3);

IntSet *Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3);

IntSet *DIfference(IntSet *s1, const IntSet *s2, const IntSet *s3);

void print(const IntSet *s);

void printLn(const IntSet *s);

void Terminate(IntSet *s);
#endif


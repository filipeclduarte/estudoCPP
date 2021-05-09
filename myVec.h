class myVector {
public:
    myVector(int s); // init
    double& operator[](int i); // indexing access elem
    int size(); // get the size
    ~myVector(); // destructor
    double mean();
    double var();
    double stDev();
    myVector operator+(const myVector& x);

private:
    double* elem;
    int sz;
    
};

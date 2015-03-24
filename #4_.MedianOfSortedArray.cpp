class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if(total % 2 == 1)
            return find(A, m, B, n, total/2 + 1);
        else
            return (find(A, m, B, n, total/2) + find(A, m, B, n, total/2 + 1))/2.0; //important for double
    }
    
private:
    static int find(int A[], int m, int B[], int n, int k){
        //assume m > n
        if(m > n)
            return find(B, n, A, m, k);
        if(m == 0)
            return B[k - 1];
        if(k == 1)
            return min(A[0], B[0]);
            
        int ia = min(k/2, m);
        int ib = k - ia;
        
        if(A[ia - 1] == B[ib - 1])
            return A[ia - 1];
        else if(A[ia - 1] > B[ib - 1])
            return find(A, m, B + ib, n - ib, k - ib);
        else if(A[ia - 1] < B[ib - 1])
            return find(A + ia, m - ia, B, n, k - ia);
    }
};
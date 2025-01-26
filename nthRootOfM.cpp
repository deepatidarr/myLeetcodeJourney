int check(int mid, int n, int m){
  long long x = 1;
  for(int i=1; i<=n; i++) {
    x = x*mid;
    if(x>m) return 2;
  }
  if(x==m) return 1;
  return 0;
}
int NthRoot(int n, int m) {
  // Write your code here.
  int lo=1, hi=m;
  while(lo<=hi){
    int mid = (lo+hi)>>1;
    int tmp = check(mid, n, m);
    if(tmp == 1) return mid;
    else if(tmp == 2) {hi = mid-1;}
    else if(tmp == 0) lo = mid+1;
  }
  return -1;
}

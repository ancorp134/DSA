//CODEsTUDIO ==> SUM OF TWO ARRAYS
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
    int aNum=0,bNum=0,final;
    vector <int> result;
    for(int i=0;i<a.size();i++){
        aNum=aNum*10+a[i];
        }
    for(int i=0;i<b.size();i++){
        bNum=bNum*10+b[i];
    }
final=aNum+bNum;
    while(final!=0){
        result.push_back(final%10);
        final=final/10;
    }
    reverse(result.begin(),result.end());
    return result;
}
public class mergesort{
  public static void main(String[] args){
    int[] arr=new int[]{8,7,6,5,4,3,2,1};
    int l=0,r=arr.length-1;
    mergesort.mergeSort(arr,l,r);
    for(int i=0;i<arr.length;i++){
    System.out.println(arr[i]);
}
}
 static void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         
         //int n=arr.length;
         int[] b=new int[arr.length];

         /*for(int i=0; i<arr.length; i++)
            b[i]=arr[i];*/


        int h=l;
        int j =m+1;
        int i=0; //i=l
            
         while(h<=m && j<=r ){
             if(arr[h]<arr[j]){
                 b[i]=arr[h];
                 h++;
                 i++;
             }
              if(arr[h]>arr[j]){
                 b[i]=arr[j];
                 j++;
                 i++;
             }
             if(h>m){
                 for(int t=j;t<=r;t++){
                     b[i]=arr[t];
                     i++;
                 }
            }
                 else{
                     for(int t=h;t<=m;t++){
                         b[i]=arr[t];
                         i++;
                     }
                 }
             
         }
         for(h=l;h<=r;h++){
             arr[h]=b[h];
         }
    }
  static  void mergeSort(int arr[], int l, int r)
    {
        if(l<r){
            int mid=(l+r)/2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, r);
            merge(arr, l, mid, r);
        }
    }
}
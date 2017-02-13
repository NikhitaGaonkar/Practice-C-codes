double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    int is_even=0, j=0,k=0;
    int prev_elem =-1, curr_elem = -1;
    int total_size = nums1Size+nums2Size;
    if(total_size %2 == 0)
      is_even =1;
   
    int mid_point = total_size/2;
    
    for(int i =0 ; i<=mid_point; i++)
    {
          if(j>=nums1Size && k<nums2Size)
          {
            prev_elem = curr_elem;
            curr_elem = nums2[k];
            k++;   
              
          }
        
          if(k>=nums2Size && j<nums1Size)
          {
            prev_elem = curr_elem;
            curr_elem = nums1[j];
            j++;   
              
          }
          if(j<nums1Size && k<nums2Size )
          {
            if(nums1[j]<nums2[k])
            { 
              prev_elem = curr_elem;
              curr_elem = nums1[j];
              j++;
            }
            else
            {
              prev_elem = curr_elem;
              curr_elem = nums2[k];
              k++;
            }
          }
        
    }
    
    if(is_even)
      return (double)(curr_elem + prev_elem)/2;
    else return curr_elem;
}

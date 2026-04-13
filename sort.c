#include <stdio.h>

#define MAX 50

int a[MAX], n;


void input() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
}


void display() {
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

void insertion() {
    for(int i=1;i<n;i++) {
        int key=a[i], j=i-1;

        while(j>=0 && a[j]>key) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;

        printf("Pass %d: ", i);
        display();
    }
}

void merge(int l,int m,int r) {
    int i=l,j=m+1,k=0,temp[MAX];

    while(i<=m && j<=r)
        temp[k++] = (a[i]<a[j])?a[i++]:a[j++];

    while(i<=m) temp[k++]=a[i++];
    while(j<=r) temp[k++]=a[j++];

    for(i=l,k=0;i<=r;i++,k++)
        a[i]=temp[k];

    printf("Merged (%d to %d): ", l, r);
    display();
}

void mergesort(int l,int r) {
    if(l<r) {
        int m=(l+r)/2;
        mergesort(l,m);
        mergesort(m+1,r);
        merge(l,m,r);
    }
}

int partition(int l,int r) {
    int pivot=a[r], i=l-1;

    for(int j=l;j<r;j++) {
        if(a[j]<pivot) {
            i++;
            int t=a[i]; a[i]=a[j]; a[j]=t;
        }
    }

    int t=a[i+1]; a[i+1]=a[r]; a[r]=t;

    printf("Pivot %d placed at index %d: ", pivot, i+1);
    display();

    return i+1;
}

void quicksort(int l,int r) {
    if(l<r) {
        int p=partition(l,r);
        quicksort(l,p-1);
        quicksort(p+1,r);
    }
}

int getMax() {
    int max=a[0];
    for(int i=1;i<n;i++)
        if(a[i]>max) max=a[i];
    return max;
}

void radix() {
    int output[MAX], count[10], max=getMax();

    for(int exp=1; max/exp>0; exp*=10) {

        for(int i=0;i<10;i++) count[i]=0;

        for(int i=0;i<n;i++)
            count[(a[i]/exp)%10]++;

        for(int i=1;i<10;i++)
            count[i]+=count[i-1];

        for(int i=n-1;i>=0;i--) {
            output[count[(a[i]/exp)%10]-1]=a[i];
            count[(a[i]/exp)%10]--;
        }

        for(int i=0;i<n;i++)
            a[i]=output[i];

        printf("After exp=%d: ", exp);
        display();
    }
}

void linear() {
    int key,flag=0;
    printf("Enter element to search: ");
    scanf("%d",&key);

    for(int i=0;i<n;i++) {
        if(a[i]==key) {
            printf("Found at index %d\n",i);
            flag=1;
        }
    }

    if(!flag) printf("Not Found\n");
}

void binary() {
    int key,l=0,r=n-1;
    printf("Enter element to search: ");
    scanf("%d",&key);

    while(l<=r) {
        int m=(l+r)/2;

        if(a[m]==key) {
            printf("Found at index %d\n",m);
            return;
        }
        else if(key<a[m])
            r=m-1;
        else
            l=m+1;
    }

    printf("Not Found\n");
}

int main() {
    int ch;

    while(1) {
        printf("\n1.Input\n2.Insertion\n3.Merge\n4.Quick\n5.Radix\n6.Linear\n7.Binary\n8.Display\n9.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1: input(); break;
            case 2: insertion(); break;
            case 3: mergesort(0,n-1); break;
            case 4: quicksort(0,n-1); break;
            case 5: radix(); break;
            case 6: linear(); break;
            case 7: binary(); break;
            case 8: display(); break;
            case 9: return 0;
            default: printf("Invalid choice\n");
        }
    }
}

#include<stdio.h>

typedef struct edge
{
    int u,v,w;
}edge;

typedef struct edgelist
{
    edge data[10];
    int n;
}edgelist;

edgelist elist;
int arr[10][10],n;
edgelist spanlist;

void uni(int belongs[],int c1,int c2)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(belongs[i]==c2)
            belongs[i]=c1;
    }
}

int find(int belongs[],int vertexno)
{
    return (belongs[vertexno]);
}

void sort()
{
    int i,j;
    edge temp;

    for(i=0;i<elist.n;i++)
    {
        for(j=0;j<elist.n-1;j++)
        {
            if(elist.data[j].w>elist.data[j+1].w)
            {
                temp=elist.data[j];
                elist.data[j]=elist.data[j+1];
                elist.data[j+1]=temp;
            }
        }
    }
}

void kruskal()
{
    int belongs[10],i,j,cno1,cno2;
    elist.n=0;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[i][j]!=0)
            {
                elist.data[elist.n].u=i;
                elist.data[elist.n].v=j;
                elist.data[elist.n].w=arr[i][j];
                elist.n++;
            }
        }
    }

    sort();

    for(i=0;i<n;i++)
        belongs[i]=i;

    spanlist.n=0;

    for(i=0;i<n;i++)
    {
        cno1=find(belongs,elist.data[i].u);
        cno2=find(belongs,elist.data[i].v);

        if(cno1!=cno2)
        {
            spanlist.data[spanlist.n]=elist.data[i];
            spanlist.n=spanlist.n+1;
            uni(belongs,cno1,cno2);
        }

    }
}

void print()
{
    int i,cost=0;
    printf("\n");
    for(i=0;i<spanlist.n;i++)
    {
        printf("\n%d\t%d\t%d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);

        cost+=spanlist.data[i].w;
    }

    printf("\nMinimum Cost: %d",cost);
}

int main()
{
    int i,j;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);


    kruskal();
    print();
}

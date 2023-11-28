# include <stdio.h>
# define MAX_SIZE 20

int sorted[MAX_SIZE]; // �߰����� ������ �ʿ�
//ī��Ʈ ������ 
int compare_count, move_count;
int c_total, m_total;
int once;//ó�� �ѹ��� ����Ŭ������ ��µǰ� 



//������Ȳ��
void print_all(int list[]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d->", list[i]);

    }
    printf("\n");
}

// i: ���ĵ� ���� ����Ʈ�� ���� �ε���
// j: ���ĵ� ������ ����Ʈ�� ���� �ε���
// k: ���ĵ� ����Ʈ�� ���� �ε���
/* 2���� ������ �迭 list[left...mid]�� list[mid+1...right]�� �պ� ���� */
/* (������ ���ڵ��� ���ĵǴ� ����) */
void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    /* ���� ���ĵ� list�� �պ� */
    while (i <= mid && j <= right) {

        compare_count++;
        move_count++;
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    // ���� �ִ� ������ �ϰ� ����
    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
        move_count++;
    }
    // ���� �ִ� ������ �ϰ� ����
    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
        move_count++;
    }
    
    // �迭 sorted[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
    for (l = left; l <= right; l++) {
        //�̰Ŵ� ���� �ӽ� �����͸� �ű�°Ϳ� �Ұ� -> ī��Ʈ�� ��� x
        list[l] = sorted[l];
       // move_count++;
    }
   if(once==0) print_all(list);
}

// �պ� ����
void merge_sort(int list[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2; // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ���� -����(Divide)
            merge_sort(list, left, mid); // ���� �κ� ����Ʈ ���� -����(Conquer)
        merge_sort(list, mid + 1, right); // ���� �κ� ����Ʈ ���� -����(Conquer)
        merge(list, left, mid, right); // ���ĵ� 2���� �κ� �迭�� �պ��ϴ� ���� -����(Combine)
    }
}

void  mergeCycle() {
    compare_count = 0;
    move_count = 0;

    int i;
    int n = MAX_SIZE;
    int list[MAX_SIZE];

    if (once == 0)printf("�ʱⰪ\n");
    for (i = 0; i < n; i++) {
        list[i] = rand() % 100;
        if (once == 0)printf("%d->", list[i]);

    }
    if (once == 0) printf("\n");
    merge_sort(list,0,n-1);

    if (once == 0) {
        printf("compare count : %d\n", compare_count);
        printf("move count : %d\n", move_count);
    }
    //printf("rand %d", rand() % 100);
    c_total += compare_count;
    m_total += move_count;


}

void main() {


    srand(time(NULL));


    mergeCycle();

    //ī��Ʈ �ʱ�ȭ 
    compare_count = 0;
    move_count = 0;

    //�� �ڿ� ���ĵ��� ��� ���� �ʰ� �� 
    once = 1;


    for (int i = 0; i < 19; i++) {
        mergeCycle();
    }


    //20�� ��� 
    printf(" compare count avg:%f\n ", (float)c_total / (float)20);
    printf("move count avg:%f\n ", (float)m_total / (float)20);
}
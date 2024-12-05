#include <stdio.h>
int main() {
        int menu, menu1;
        int n = 0;
        int index;
        int temp;
        int pos;
        int j, key;
        int arr[100];
        int mid,right, left;
        menu:
        do {
                printf("1.Nhập số phần tử và giá trị cho mảng\n");
                printf("2.In ra giá trị các phần tử trong mảng\n");
                printf("3.Đếm số lượng các số hoàn hảo có trong mảng. Biết số hoàn hảo là số có tổng các ước bằng chính nó\n");
                printf("4.Tìm giá trị lớn thứ 2 trong mảng, không được sắp xếp mảng\n");
                printf("5.Thêm một phần tử vào vị trí ngẫu nhiên trong  mảng, phần tử mới thêm vào mảng và vị trí thêm vào phải do người dùng nhập vào	\n");
                printf("6.Xóa phần tử tại một vị trí cụ thể (người dùng nhập vị trí)\n");
                printf("7.Sắp xếp mảng theo thứ tự tăng dần (Insertion sort)\n");
                printf("8.Cho người dùng nhập vào một phần tử, tìm kiếm xem phần tử đó có tồn tại trong mảng hay không (Binary search)\n");
                printf("9.Sắp xếp lại mảng và hiển thị ra toàn bộ phần tử có trong mảng sao cho toàn bộ số chẵn đứng trước, số lẻ đứng sau\n");
                printf("10.Đảo ngược thứ tự của các phần tử có trong mảng\n");
                printf("11.Thoat!\n");
                printf("Enter your number: ");
                scanf("%d", &menu);
        }while(menu > 11 || menu < 1);

        switch (menu) {
                case 1:
                        do {
                                printf("Nhập số phần tử: ");
                                scanf("%d", &n);
                                if(n < 1 || n > 100) {
                                        printf("invalid!!\n");
                                }
                        }while (n < 1 || n > 100);

                        for (int i = 0; i < n; i++) {
                                printf("Nhap gia tri phan tu arr[%d]: ", i);
                                scanf("%d", &arr[i]);
                        }
                        goto menu1;
                        break;

                case 2:
                        if( n == 0) {
                                printf("Chua nhap mang\n");
                                goto menu1;
                        }
                        for (int i = 0; i < n; i++) {
                                printf("arr[%d]\n", arr[i]);
                        }
                        goto menu1;
                        break;

                case 3:
                        if( n == 0) {
                                printf("Chua nhap mang\n");
                                goto menu1;
                        }
                        index = 0;
                       for (int i = 0; i < n; i++) {
                               temp = 0;
                              for(int j = arr[i]; j > 0; j--) {
                                      if(arr[i] % j == 0) {
                                              temp++;
                                      }
                              }
                               if(temp == 2) {
                                       index++;
                               }
                        }


                        printf(" tong so nguen to la %d", index);
                        goto menu1;
                        break;

                case 4:
                        if( n == 0) {
                                printf("Chua nhap mang\n");
                                goto menu1;
                        }
                        index = 0;
                        for (int i = 0; i < n; i++) {
                                if(arr[i] > arr[index]) {
                                        index = i;
                                }
                        }
                        temp = arr[index];
                        arr[index] = arr[0];
                        arr[0]  = temp;
                         for (int i = 1; i < n; i++) {
                                if(arr[i] > arr[index]) {
                                        index = i;
                                }
                        }
                        printf("Gia tri lon thu 2 la %d ", arr[index]);
                        goto menu1;
                        break;

                case 5:
                        if( n == 0) {
                                printf("Chua nhap mang\n");
                                goto menu1;
                        }
                        printf("vi tri muon them: ");
                        scanf("%d", &pos);
                        pos--;
                         for (int i = n - 1; i > 0; i--) {
                                 arr[i + 1] = arr[i];
                                 if(i == pos){
                                         printf("gia tri muon nhap: ");
                                         scanf("%d", &arr[i]);
                                         break;
                                 }
                         }
                        n++;
                         for (int i = 0; i < n; i++) {
                                printf("arr[%d]\n", arr[i]);
                        }
                        goto menu1;
                        break;

                case 6:
                        if( n == 0) {
                                printf("Chua nhap mang\n");
                                goto menu1;
                        }
                        printf("Vi tri can xoa: ");
                        scanf("%d", &pos);
                        pos--;
                        for(int i = pos; i < n; i++) {
                                arr[i] = arr[i+ 1];
                        }
                        n--;
                        for (int i = 0; i < n; i++) {
                                printf("arr[%d]\n", arr[i]);
                        }
                        goto menu1;
                        break;

                case 7:
                        // 7 1 8 9 6 4 1
                        if( n == 0) {
                                printf("Chua nhap mang\n");
                                goto menu1;
                        }

                        for (int i = 1; i < n; i++) {
                           key = arr[i];
                           j = i - 1;
                                while( j >= 0 && arr[j] > key) {
                                        arr[j + 1] = arr[j];
                                        j--;
                                }
                                arr[j + 1] = key;
                        }


                        for (int i = 0; i < n; i++) {
                                printf("%d ", arr[i]);
                        }
                        goto menu1;
                        break;

                case 8:
                        if( n == 0) {
                                printf("Chua nhap mang\n");
                                goto menu1;
                        }
                        printf("Nhap phan tu can tim: ");
                        scanf("%d", &pos);
                        left = 0;
                        right = n - 1;
                        while (left <= right) {
                                mid = left + (right - left) / 2;
                                if(arr[mid] == pos) {
                                        printf("Phan tu nam o vi tri: %d", mid + 1);
                                        break;
                                }else if(arr[mid] > right) {
                                        right = mid - 1;
                                }else {
                                        left = mid + 1;
                                }
                        }
                        goto menu1;
                        break;

                case 9:
                        if( n == 0) {
                                printf("Chua nhap mang\n");
                                goto menu1;
                        }
                        for (int i = 0; i < n; i++) {
                                if(arr[i] % 2 == 0) {
                                        printf("%d ", arr[i]);
                                }
                        }
                        printf("| ");
                        for (int i = 0; i < n; i++) {
                                if(arr[i] % 2 != 0) {
                                        printf("%d ", arr[i]);
                                }
                        }
                        goto menu1;
                        break;

                case 10:
                        if( n == 0) {
                                printf("Chua nhap mang\n");
                                goto menu1;
                        }
                        for (int i = n -1; i >= 0; i--) {
                                printf("%d ", arr[i]);
                        }

                        goto menu1;
                        break;

                case 11:
                        if( n == 0) {
                                printf("Chua nhap mang\n");
                                goto menu1;
                        }
                        printf("Da thoat!");
                        return 0;
                menu1:
                printf("\n");
                do {
                        printf("1.Back to menu\n");
                        printf("2.Exit\n");
                        scanf("%d", &menu1);
                }while (menu1 != 1 && menu1 != 2);
                if(menu1 == 1) {
                        goto menu;
                }else {
                        return 0;
                }

                        break;
        }
}

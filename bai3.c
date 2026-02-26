/******************************************************************************
 * Họ và tên: [Nguyễn Phúc Nhân]
 * MSSV:      [PS47835]
 * Lớp:       [CS21301]
 *****************************************************************************/

//  BÀI 3: TÌM KIẾM SINH VIÊN

// VIẾT CODE Ở ĐÂY

#include <stdio.h>
#include <string.h>
struct nhapThongTinSinhVien
{
    char MSSV[15];
    char tenSinhVien[100];
    char nganhHoc[50];
    float diemTrungBinh;
};
int main()
{
    int soSinhVien;

    printf("Bạn hãy nhập vào số sinh viên: ");
    scanf("%d", &soSinhVien);

    struct nhapThongTinSinhVien mangThongTin[soSinhVien];

    for(int i = 0; i < soSinhVien; i++)
    {
        // Nhập mã số sinh viên
        printf("Nhập mã số sinh viên thứ %d: ", i+1);
        scanf("%s", &mangThongTin[i].MSSV);
        getchar();
        // Nhập họ tên sinh viên
        printf("Nhập họ và tên sinh viên %d: ", i+1);
        gets(mangThongTin[i].tenSinhVien);

        // Nhập tên ngành học
        printf("Nhập tên ngành học của sinh viên thứ %d: ", i+1);
        gets(mangThongTin[i].nganhHoc);

        // Nhập điểm trung bình
        do
        {
          
        printf("Điểm trung bình của sinh viên thứ %d: ", i+1);
        scanf("%f", &mangThongTin[i].diemTrungBinh);
        getchar();
        } while (mangThongTin[i].diemTrungBinh < 0 || mangThongTin[i].diemTrungBinh > 10);
    }
    char timKiem[15];

    // Nhập mã số sinh viên cần tìm kiếm
    printf("Nhập mã số sinh viên bạn cần tìm kiếm: ");
    gets(timKiem);

    for(int i = 0; i < soSinhVien; i++)
    {
        if(strcmp(mangThongTin[i].MSSV, timKiem) == 0)
        {
           printf("********THÔNG TIN SINH VIÊN*********\n");
           printf("%-5s | %-15s | %-25s      | %-20s         | %-15s  \n",  "Số thứ tự", "MSSV", "Tên Sinh Viên", "Ngành học","Điểm trung bình");
           printf("%-9d | %-15s | %-25s | %-20s | %-15.2f \n", i+1, mangThongTin[i].MSSV, mangThongTin[i].tenSinhVien, mangThongTin[i].nganhHoc, mangThongTin[i].diemTrungBinh);
        }
    }
    return 0;
}   
    
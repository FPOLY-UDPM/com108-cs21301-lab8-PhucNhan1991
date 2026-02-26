/******************************************************************************
 * Họ và tên: [Nguyễn Phúc Nhân]
 * MSSV:      [PS47835]
 * Lớp:       [CS21301]
 *****************************************************************************/

//  BÀI 1: XÂY DỰNG CHƯƠNG TRÌNH LƯU THÔNG TIN SINH VIÊN 
//  Input: Nhập vào từ bàn phím các thông tin sinh viên như: mã số sinh viên, tên sinh 
//  viên, ngành học, điểm trung bình. 
//  Output: Xuất ra thông tin của tất cả sinh viên trên màn hình

// VIẾT CODE Ở ĐÂY
/*
    XÂY DỰNG CHƯƠNG TRÌNH NHẬP THÔNG TIN SINH VIÊN
Input:
   B1: Thông tin sinh viên chứa các thông tin sau: mã số sinh viên, tên sinh viên, ngành học, điểm trung bình
    Với yêu cầu thông tin sinh viên như trên ta phải dùng kiểu dữ liệu cấu trúc vì chứa nhiều thông tin có kiểu dữ liệu khác nhau
        Mã số sinh viên : kiểu chuỗi
        Tên sinh viên : kiểu chuỗi
        Ngành học: kiểu chuỗi
        Điểm trung bình : kiểu số thực
    Với kiểu dữ liệu cấu trúc ta phải khai báo như sau:
        struct <tên cấu trúc>
        {
            char MSSV[15];
            char tenSinhVien[100];
            char nganhHoc[50];
            float diemTrungBinh;
        }
    B2 : Nhập vào lần lượt thông tin của sinh viên
        Đầu tiên ta phải tạo 1 vùng chứa dữ liệu thông tin sinh viên của rất nhiều sinh viên
            Khai báo biến số sinh viên 
            Cho người dùng nhập vào số sinh viên 
            mangThongTin[n]
        Do công việc nhập là 1 công việc được lặp đi lặp lại nên ta sử dụng vòng lặp để thực hiện 
            for( biến đếm = 0; biến đếm < số sinh vien; biến đếm tăng 1 )
            {
                Với thành viên mã số sinh viên:
                    printf("Nhập mã số sinh viên thứ %d: ", i)
                    scanf("%s", &mangThongTin[i].MSSV)
                
                Với thành viên tên sinh viên
                    printf("Nhập tên sinh viên thứ %d: ", i)
                    gets(mangThongTin[i].tenSinhVien)
                
                Với thành viên ngành học
                    printf("Nhập ngành học thứ %d: ", i)
                    gets(mangThongTin[i].nganhHoc)
                
                Với thành viên điểm trung bình
                    printf("Nhập điểm trung bình của sinh viên thứ %d", i)
                    scanf("%d", &mangThongTin[i].diemTrungBinh)
            }
Process: Xuất thông tin của từng sinh viên 
    Tạo 1 bảng chứa thông tin từ 1 cho đến n\
    printf("%-6s | %-15s | %-12s | %-12s | %-15s | %-15s \n", "Số thứ tự", "MSSV", "Tên Sinh Viên", )
    
    Lặp lại công việc in ra từ sinh viên thứ 0 đến sinh viên thứ n trong mangThongTin
    
    for(int i = 0; i < n; i++)
    {
        printf("%3d | %-5s  | " )
    }
*/
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
        printf("Điểm trung bình của sinh viên thứ %d: ", i+1);
        scanf("%f", &mangThongTin[i].diemTrungBinh);
    }

// Bài 2: Sắp xếp điểm trung bình của các sinh viến vừa nhập theo thứ tự tăng dần
    for(int i = 0; i < soSinhVien; i++)
    {
        for( int j = i + 1; j < soSinhVien; j++)
        {
            if(mangThongTin[i].diemTrungBinh > mangThongTin[j].diemTrungBinh)
            {
                struct nhapThongTinSinhVien SvTam;
                SvTam = mangThongTin[i];
                mangThongTin[i] = mangThongTin[j];
                mangThongTin[j] = SvTam;

            }
        }
    }





//  In thông tin sinh viên
    printf("********THÔNG TIN SINH VIÊN*********\n");
    printf("%-5s | %-15s | %-25s      | %-20s         | %-15s  \n",  "Số thứ tự", "MSSV", "Tên Sinh Viên", "Ngành học","Điểm trung bình");

    for(int i = 0; i < soSinhVien; i++)
    {
        printf("%-9d | %-15s | %-25s | %-20s | %-15.2f \n", i+1, mangThongTin[i].MSSV, mangThongTin[i].tenSinhVien, mangThongTin[i].nganhHoc, mangThongTin[i].diemTrungBinh);
    }

    
    return 0;
}


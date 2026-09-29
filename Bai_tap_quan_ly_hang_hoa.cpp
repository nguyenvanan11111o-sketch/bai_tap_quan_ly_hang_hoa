using System;

class Ngay
{
    public int ngay;
    public int thang;
    public int nam;
}

class HangHoa
{
    public string ma = "";
    public string ten = "";
    public Ngay ngayxuat = new Ngay();
    public double gia;
}

class Program
{
    static void NhapHangHoa(HangHoa h)
    {
        Console.Write("Nhap ma hang: ");
        h.ma = Console.ReadLine() ?? "";

        Console.Write("Nhap ten hang: ");
        h.ten = Console.ReadLine() ?? "";

        Console.Write("Nhap ngay xuat: ");
        h.ngayxuat = new Ngay();

        Console.Write("Ngay: ");
        h.ngayxuat.ngay = int.Parse(Console.ReadLine() ?? "0");

         Console.Write("Thang: ");
        h.ngayxuat.thang = int.Parse(Console.ReadLine() ?? "0");

         Console.Write("Nam: ");
        h.ngayxuat.nam = int.Parse(Console.ReadLine() ?? "0");

        Console.Write("Nhap gia: ");
        h.gia = double.Parse(Console.ReadLine() ?? "0");
    }

    static void NhapDanhSach(HangHoa[] ds)
    {
        for (int i = 0; i < ds.Length; i++)
        {
            Console.WriteLine("\n--- Nhap hang hoa thu " + (i + 1) + "---");

            ds[i] = new HangHoa();

            NhapHangHoa(ds[i]);
        }
    }

    static void XuatDS(HangHoa[] ds)
    {
        Console.WriteLine("\n========== DANH SACH HANG HOA ==========");

        for(int i = 0; i < ds.Length; i++)
        {
            Console.WriteLine("\nHang hoa thu " + (i+1));
            Console.WriteLine("Ma hang: " + ds[i].ma);
            Console.WriteLine("Ten hang: " + ds[i].ten);

            Console.WriteLine(
                "Ngay xuat: " + 
                ds[i].ngayxuat.ngay + "/" +
                ds[i].ngayxuat.thang + "/" +
                ds[i].ngayxuat.nam
            );

            Console.WriteLine("Gia: " + ds[i].gia);
        }
    }

    static void SelectionSort(HangHoa[] ds)
    {
        for(int i = 0; i < ds.Length; i++)
        {
            int min = i;

            for(int j = i + 1; j < ds.Length; j++)
            {
                if(ds[j].gia < ds[min].gia)
                {
                    min = j;
                }
            }
            HangHoa temp = ds[i];
            ds[i] = ds[min];
            ds[min] = temp;
        }
    }

        static int BinarySearch(HangHoa[] ds, double giaCanTim)
    {
        int left = 0;
        int right = ds.Length - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (ds[mid].gia == giaCanTim)
            {
                return mid;
            }
            else if (ds[mid].gia < giaCanTim)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }

    static void Main()
    {
        Console.Write("Nhap so luong hang hoa: ");
        int n = int.Parse(Console.ReadLine() ?? "0");

        HangHoa[] ds = new HangHoa[n];

        NhapDanhSach(ds);

        Console.WriteLine("\n--- DANH SACH BAN DAU ---");
        XuatDS(ds);

        SelectionSort(ds);

        Console.WriteLine("\n--- DANH SACH SAU KHI SAP XEP ---");
        XuatDS(ds);

        Console.Write("\nNhap gia can tim: ");
        double giacantim = double.Parse(Console.ReadLine() ?? "0");

        int vitri = BinarySearch(ds, giacantim);

        if (vitri != -1)
        {
            Console.WriteLine("\nTim thay hang hoa: ");
            Console.WriteLine("Ma hang: " + ds[vitri].ma);
            Console.WriteLine("Ten hang: " + ds[vitri].ten);

            Console.WriteLine(
                "Ngay xuat: " +
                ds[vitri].ngayxuat.ngay + "/" +
                ds[vitri].ngayxuat.thang + "/" +
                ds[vitri].ngayxuat.nam
            );

            Console.WriteLine("Gia: " + ds[vitri].gia);
        }
        else
        {
            Console.WriteLine("\nKhong tim thay hang hoa co gia " + giacantim);
        }
    }
}

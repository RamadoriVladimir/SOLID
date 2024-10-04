#include <iostream>
#include <string>
using namespace std;

class PDFReport
{
public:
    void generatePDF()
    {
        cout << "Generando reporte en PDF" << endl;
    }
};

class ExcelReport
{
public:
    void generateExcel()
    {
        cout << "Generando reporte en Excel" << endl;
    }
};

class ReportService
{
private:
    PDFReport pdfReport; // Depende directamente de las implementaciones concretas
    ExcelReport excelReport;

public:
    void generateReport(string type)
    {
        if (type == "PDF")
        {
            pdfReport.generatePDF(); 
        }
        else if (type == "Excel")
        {
            excelReport.generateExcel(); 
        }
        else
        {
            cout << "Formato de reporte desconocido" << endl;
        }
    }
};

int main()
{
    ReportService reportService;

    reportService.generateReport("PDF");   
    reportService.generateReport("Excel");

    return 0;
}

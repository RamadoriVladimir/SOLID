#include <iostream>
#include <string>
using namespace std;

class IReport
{
public:
    virtual void generate() = 0;
    virtual ~IReport() = default;
};

class PDFReport : public IReport
{
public:
    void generate() override
    {
        cout << "Generando reporte en PDF" << endl;
    }
};

class ExcelReport : public IReport
{
public:
    void generate() override
    {
        cout << "Generando reporte en Excel" << endl;
    }
};

class ReportService
{
private:
    IReport &report; // Depende de la abstracción, no de la implementación concreta

public:
    ReportService(IReport &reportType) : report(reportType) {}

    void generateReport()
    {
        report.generate(); 
    }
};

int main()
{
    PDFReport pdfReport;
    ReportService reportService(pdfReport);
    reportService.generateReport();       

    ExcelReport excelReport;
    ReportService anotherService(excelReport); 
    anotherService.generateReport();   

    return 0;
}

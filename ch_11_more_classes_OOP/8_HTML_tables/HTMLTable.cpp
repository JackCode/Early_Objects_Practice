#include "HTMLTable.h"

void HTMLTable::writeRow(ostream &out, string tag, vector<string> row) {

    out << "  <tr>\n";

    for (const string &data : row)
    {
        out << "    <" << tag << "> ";
        out << data;
        out << " </" << tag << ">\n";
    }
    
    out << "  </tr>\n";

}

void HTMLTable::writeRow(ostream &out, string tag, Student row) {

    out << "  <tr>\n";

    out << "    <" << tag << "> ";
    out << row.studentName;
    out << " </" << tag << ">\n";
    
    out << "    <" << tag << "> ";
    out << row.studentScore;
    out << " </" << tag << "> ";

    out << "\n  </tr>\n";

}

ostream & operator<< (ostream &out, HTMLTable htmltable) {

    out << "<table border = \"1\">\n";
    htmltable.writeRow(out, "th", htmltable.headers);
    
    for (const HTMLTable::Student &student : htmltable.classroom)
        htmltable.writeRow( out, "td", student );

    out << "</table>";

    return out;

}
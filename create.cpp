#include <iostream>
#include <string>
#include <direct.h>
#include "ext/tinyfiledialogs.h"
#include <algorithm>
#include <sys/stat.h>
#include <fstream>

using namespace std;

int main()
{

    string name;
    string author;
    string cl;

    cout << "Masukkan nama plugin: ";
    getline(cin, name);
    cout << "Masukkan nama author: ";
    getline(cin, author);
    cout << "Example: 'nameplugin/author'\nMasukkan class (opsional, tekan Enter untuk default): ";
    getline(cin, cl);

    if (cl.empty())
    {
        cl = name + "/" + author;
    }

    const char *selectedDir = tinyfd_selectFolderDialog("Pilih Folder", NULL);
    if (selectedDir)
    {
        string newDirPath = string(selectedDir) + "\\" + name;
        replace(newDirPath.begin(), newDirPath.end(), '/', '\\');
        replace(cl.begin(), cl.end(), '/', '\\');
        struct _stat buffer;
        if (_stat(newDirPath.c_str(), &buffer) == 0)
        {
            cout << "\nDirektori sudah ada: " << newDirPath << endl;
            cout << "\nTekan Enter untuk keluar...";
            cin.ignore();
            cin.get();
            return 0;
        }
        else
        {
            if (_mkdir(newDirPath.c_str()) == 0)
            {
                cout << "\nDirektori berhasil dibuat: " << newDirPath << endl;
                string srcDir = newDirPath + "\\src";
                if (_mkdir(srcDir.c_str()) == 0)
                {
                    string mainFilePath = srcDir + "\\Main.php";
                    ofstream mainFile(mainFilePath);
                    if (mainFile.is_open())
                    {
                        mainFile << "<?php\n\n";
                        mainFile << "declare(strict_types=1);\n\n";
                        mainFile << "namespace " << cl << ";\n\nuse pocketmine\\plugin\\PluginBase;\n\n";
                        mainFile << "class Main extends PluginBase{\n\n";
                        mainFile << "    public function onEnable() : void {\n";
                        mainFile << "        //© xeonch a.k.a jasson\n";
                        mainFile << "    }\n";
                        mainFile << "}\n";
                        mainFile.close();
                        cout << "\nFile 'Main.php' berhasil dibuat." << endl;
                    }
                    else
                    {
                        cout << "\nGagal membuat file 'Main.php'." << endl;
                        cout << "\nTekan Enter untuk keluar...";
                        cin.ignore();
                        cin.get();
                        return 0;
                    }
                }
                else
                {
                    cout << "\nGagal membuat subfolder 'src'." << endl;
                    cout << "\nTekan Enter untuk keluar...";
                    cin.ignore();
                    cin.get();
                    return 0;
                }

                string pluginFilePath = newDirPath + "\\plugin.yml";
                ofstream pluginFile(pluginFilePath);
                replace(cl.begin(), cl.end(), '/', '\\');
                if (pluginFile.is_open())
                {
                    pluginFile << "name: " << name << "\n";
                    pluginFile << "version: 1.0.0\n";
                    pluginFile << "main: " << cl << "\\Main\n";
                    pluginFile << "api: 5.0.0\n";
                    pluginFile << "src-namespace-prefix: " << cl << "\n";
                    pluginFile << "author: " << author << "";
                    pluginFile.close();
                    cout << "File 'plugin.yml' berhasil dibuat." << endl;
                }
                else
                {
                    cout << "Gagal membuat file 'plugin.yml'." << endl;
                    cout << "\nTekan Enter untuk keluar...";
                    cin.ignore();
                    cin.get();
                    return 0;
                }
            }
            else
            {
                cout << "\nGagal membuat direktori utama." << endl;
                cout << "\nTekan Enter untuk keluar...";
                cin.ignore();
                cin.get();
                return 0;
            }
        }
    }
    else
    {
        cout << "\nTidak ada direktori yang dipilih." << endl;
        cout << "\nTekan Enter untuk keluar...";
        cin.ignore();
        cin.get();
        return 0;
    }

    cout << "\nHasil:\n" << endl;
    cout << "Nama Plugin: " << name << endl;
    cout << "Author: " << author << endl;
    cout << "Class: " << cl << endl;
    cout << "\nTekan Enter untuk keluar...";
    cin.ignore();
    cin.get();
    return 0;
}

#pragma once
#include "FileSystem.h"
#include "FileBinderCri.h"

namespace app
{
namespace fnd
{
class FileSystemCri : public FileSystem // size = 0x118
{
public:
    FileBinderCri* Binder; // TODO: Is this actually part of FileSystem??

    /*
        @brief Constructor for FileSystemCri.
        <b>Wii U: 0x0219320c, PC: TODO</b>
    */
    FileSystemCri();

    /*
        @brief Destructor for FileSystemCri.
        <b>Wii U: 0x021932d8, PC: TODO</b>
    */
    ~FileSystemCri() override;

    /* <b>Wii U: 0x02193394, PC: TODO</b> */
    void Update() override;

    /* <b>Wii U: 0x0219338c, PC: TODO</b> */
    FileBinder* GetDefaultBinder() const override;

    // TODO
};
}
}

#pragma once
namespace app
{
namespace fnd
{
struct Message
{
    unsigned int Type;
    unsigned int Fx08 = 0;
    unsigned int Fx0C = 0;
    unsigned int Fx10 = 0;
    int Fx14 = -1;

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual Message* Clone() const;

    /*
        @brief Destructor for Message.
        <b>Wii U: TODO, PC: TODO</b>
    */
    virtual ~Message() = default;

    /*
        @brief Constructor for Message.
        <b>Wii U: TODO, PC: TODO</b>
    */
    Message(unsigned int type);
};
}
}

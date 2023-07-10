#pragma once

namespace app
{
namespace Player
{
class CPlayer;

namespace Param
{
enum Index // TODO: Is this actually an enum?
{
    // TODO
};

namespace Type
{
enum EType__
{
    // TODO
};
} // Type

namespace Level
{
enum ELevel__
{
    // TODO
};
} // Level
} // Param

class CParameterGOC
{
    // TODO

public:
    LWAPI(0x0294e3f0, TODO)
    CParameterGOC(CPlayer* param_1);

    LWAPI(0x0294e468, TODO)
    ~CParameterGOC();

    LWAPI(0x0294e4e8, TODO)
    void Initialize();

    LWAPI(0x0294e4f4, TODO)
    void Update(float param_1);

    LWAPI(0x0294e590, TODO)
    void ChangeParam(Param::Type::EType__ param_1);

    LWAPI(0x0294e618, TODO)
    void SetupCommonParameter();

    LWAPI(0x0294e77c, 0x0294e77c)
    float Get(Param::Index param_1) const;

    LWAPI(0x0294e9b4, TODO)
    void SwapParam(Param::Type::EType__ param_1);

    LWAPI(0x0294eab4, TODO)
    void ResetParam(Param::Type::EType__ param_1);

    LWAPI(0x0294ebdc, TODO)
    void GetParamType(Param::Level::ELevel__ param_1) const;
};
} // Player
} // app

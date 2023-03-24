// TODO: Both the name of this file and its path were guessed!
#include "pch.h"
#include "csl/math/quaternion.h"
#include "csl/math/vector3.h"

namespace csl
{
namespace math
{
const Vector3 Vector3::Zero = Vector3(0.0f, 0.0f, 0.0f);

const Vector3 Vector3::One = Vector3(1.0f, 1.0f, 1.0f);

const Vector3 Vector3::NegativeOne = Vector3(-1.0f, -1.0f, -1.0f);

const Vector3 Vector3::Right = Vector3(1.0f, 0.0f, 0.0f);

const Vector3 Vector3::Up = Vector3(0.0f, 1.0f, 0.0f);

const Vector3 Vector3::Forward = Vector3(0.0f, 0.0f, 1.0f);
} // math
} // csl

#pragma once

namespace math
{
	/**
	 * @brief 泛型泛型加法函数
	 * @tparam T 支持加法运算的任意类型
	 * @param a 第一个操作数
	 * @param b 第二个操作数
	 * @return 两个操作数的和
	 */
	template <typename T>
	T add(T a, T b)
	{
		return a + b;
	}

	/**
	 * @brief 实现泛型乘法函数
	 * @tparam T 支持乘法运算的任意类型
	 * @param a 第一个操作数
	 * @param b 第二个操作数
	 * @return 两个操作数的积
	 */
	template <typename T>
	T multiply(T a, T b)
	{
		return a * b;
	}

	/**
	 * @brief 实现泛型减法函数
	 * @tparam T 支持减法运算的任意类型
	 * @param a 被减数
	 * @param b 减数
	 * @return 两个操作数的差
	 */
	template <typename T>
	T subtract(T a, T b)
	{
		return a - b;
	}

	/**
	 * @brief 实现泛型除法函数
	 * @tparam T 支持除法运算的任意类型
	 * @param a 被除数
	 * @param b 除数
	 * @return 两个操作数的商
	 */
	template <typename T>
	T divide(T a, T b)
	{
		// 对于整数类型，可以添加除以零的检查
		return a / b;
	}
}

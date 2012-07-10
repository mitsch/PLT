///
/// @file Token.hpp
/// @author Michael Koch
/// @copyright CC BY 3.0
///

#ifndef __PLT_TOKEN_HPP__
#define __PLT_TOKEN_HPP__

namespace plt
{

	/// @struct	Token
	/// @brief	Token represents one entity in a formal language
	///
	/// @tparam	Type	type type of tokens
	/// @tparam	Value	value type of tokens
	///
	/// @details	asd
	template <typename Type, typename Value>
	struct Token
	{
		/// type of token
		Type type;
		
		/// value of token
		Value value;
		
		/// @brief	constructor sets attributes
		/// @param[in] type	type of token
		/// @param[in] value	value of token
		constexpr Token(Type const& type, Value const& value) :
			type(type) ,
			value(value)
		{}		
	};

}

#endif


///
/// @file DFA.hpp
/// @author Michael Koch
/// @copyright CC BY 3.0
///

#ifndef __PLT_DFA_HPP__
#define __PLT_DFA_HPP__

namespace plt
{

	/// @class DFA
	/// @brief deterministic finite automate
	/// 
	/// @tparam State type of state
	/// @tparam Character type of input characters
	/// @tparam Transition type of transition function
	template <typename State, typename Character, typename Transition>
	class DFA
	{
	
		private:
		
			/// current state of automate
			State currentState;
			
			/// initial state of automate
			State const initialState;
			
			/// transition function
			Transition const transition;
			
		public:
		
			/// @brief get current state of the automate
			/// @return current state
			constexpr State const& GetState()
			{
				return currentState;
			}
			
			/// @brief set current state of the automate
			/// @param[in] state new state to set
			void SetState(State const& state)
			{
				currentState = state;
			}
			
			/// @brief reset automate, so that current state equals initial state
			void Reset()
			{
				currentState = initialState;
			}
			
			/// @brief take one input character and transfer the automate into a new state
			/// @return new state of automate
			/// @param[in] character input character which decides which will be the new state
			/// @note The new state also depends on the actual state.
			State const& Proceed(Character const& character)
			{
				currentState = transition(currentState, character);
				return currentState;
			}
			
			/// @brief constructor sets attributes
			/// @param[in] initial initial state of the automate
			/// @param[in] current current state of the automate
			/// @param[in] transition transition function
			/// @note The automate will start in the \a current state rather than the \a initial state.
			///		  But reseting will put the automate in the \a initial state.
			constexpr DFA(State const& initial, State const& current, Transition const& transition) :
				currentState(current),
				initialState(initial),
				transition(transition)
			{}
			
			/// @brief constructor sets attributes
			/// @param[in] initial initial state of the automate
			/// @param[in] transition transition function
			/// @note The automate will start in the \a initial start.
			constexpr DFA(State const& initial, Transition const& transition) :
				currentState(initial),
				initialState(initial),
				transition(transition)
			{}
	};

}

#endif


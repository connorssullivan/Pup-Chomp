#include <stack>
#include <memory>

#include "Config.h"
#include "State.h"

namespace Engine 
{
    class StateMan
    {
        private:
            bool m_add;
            bool m_replace;
            bool m_remove;

            std::stack<std::unique_ptr<State>> m_stateStack;
            std::unique_ptr<State> m_newState;
        public:
            StateMan();
            ~StateMan();

            void Add(std::unique_ptr<State> toAdd, bool replace = false);
            void PopCurrent();
            void ProcessStateChanged();
            std::unique_ptr<Engine::State>& GetCurrent();
    };  
};
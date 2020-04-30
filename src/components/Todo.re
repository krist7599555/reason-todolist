type item = TodoType.item;
type state = {
  items: list(item),
  input: string,
};

let init_state = () => {
  input: "test",
  items: [
    { name: "hello", completed: true },
    { name: "apolo", completed: false }
  ]
}

type action =
  | AddItem(item)
  | RemoveItem(item)
  | ChangeInput(string)
  | ToggleItem(string);

let reducer = (state, action) =>
  switch (action) {
  | AddItem(item)      => {items: [item, ...state.items], input: "" }
  | RemoveItem(item)   => {...state, items: List.filter((elem: item) => elem.name != item.name, state.items) }
  | ChangeInput(input) => {...state, input }
  | ToggleItem(name)   => {...state, items: state.items 
    |> List.map((item: item) => item.name == name
        ? { ...item, completed: !item.completed }
        : item
      )
    }
  };

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, init_state());
  <div className="app-header">
    <div className="title"> {ReasonReact.string("Todo List")} </div>
    <div> {
      state.items
      |> List.map(item => 
          <TodoItem 
            item={item} 
            onChange={_val => dispatch(ToggleItem(item.name))}
            key={item.name}
          ></TodoItem>
        )
      |> Array.of_list 
      |> React.array
    } </div>
    <hr/>
    <div>{React.string(state.input)}</div>
    <form onSubmit={event => {
      ReactEvent.Form.preventDefault(event);
      dispatch(AddItem({ name: state.input, completed: false }));
    }}>
      <input 
        className="p-1" 
        value={state.input}
        onChange={event => event
          |> ReactEvent.Form.target
          |> target => dispatch(ChangeInput(target##value))
        }
      ></input>
      <button className="px-4 py-1 bg-primary text-white rounded" type_="submit">
        {React.string("add")}
      </button>
    </form>
  </div>
};
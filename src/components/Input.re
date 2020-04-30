
[@react.component]
let make = (~value, ~onInputText, ~submit, _children) => {
    <div className="input">
      <input
        value
        placeholder="Enter item and click add"
        onChange=(event => onInputText(ReactEvent.Form.target(event)##value))
      />
      <button onClick=(_ => submit())> (ReasonReact.string("Add")) </button>
    </div>
};
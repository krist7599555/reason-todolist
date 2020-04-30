[@react.component]
let make = (~item: TodoType.item, ~onChange=Js.log) => {
  <div className="item flex w-full justify-between">
    <p>{React.string(item.name)}</p>
    <input
      type_="checkbox"
      checked=item.completed
      onChange={_event => onChange(!item.completed)}
    />
  </div>
};
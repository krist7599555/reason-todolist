
let str = ReasonReact.string;
[@react.component]
let make = () => {
  <div className="bg-gray-200 h-screen fixed left-0 p-3"> 
    <div>(str("logo"))</div>
    <div>(str("login"))</div>
  </div>;
};

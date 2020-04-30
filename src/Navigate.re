
let str = ReasonReact.string;
[@react.component]
let make = () => {
  <div className="bg-gray-200 h-screen fixed left-0 p-3"> 
    <a href="/">     <div className="transform -rotate-90 py-10 hover:text-primary">(str("logo"))</div></a>
    <a href="/login"><div className="transform -rotate-90 py-10 hover:text-primary">(str("login"))</div></a>
    <a href="/todo"> <div className="transform -rotate-90 py-10 hover:text-primary">(str("todo"))</div></a>
    <a href="/">     <div className="transform -rotate-90 py-10 hover:text-primary">(str("home"))</div></a>
  </div>;
};

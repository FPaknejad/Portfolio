import React, { useCallback, useState } from 'react';
import ReactFlow, {
  ReactFlowProvider,
  MiniMap,
  Controls,
  Background
} from 'reactflow';
import 'reactflow/dist/style.css';

const nodeTypes = {
  default: ({ data }) => (
    <div className="p-2 bg-white rounded-xl shadow-md border text-sm">
      {data.label}
    </div>
  )
};

function parseJsonToElements(json) {
  if (!json || !json.nodes) return { nodes: [], edges: [] };

  const levelMap = {};
  const spacingX = 250;
  const spacingY = 100;

  // Determine depth level for each node
  const getDepth = (nodeId, visited = new Set()) => {
    if (visited.has(nodeId)) return 0;
    visited.add(nodeId);
    const node = json.nodes.find((n) => n.id === nodeId);
    if (!node || !node.parent) return 0;
    return 1 + getDepth(node.parent, visited);
  };

  // Assign positions
  const nodes = json.nodes.map((node, index) => {
    const depth = getDepth(node.id);
    if (!levelMap[depth]) levelMap[depth] = [];
    levelMap[depth].push(node.id);

    const x = depth * spacingX;
    const y = levelMap[depth].length * spacingY;

    return {
      id: node.id,
      type: 'default',
      data: { label: node.label },
      position: { x, y }
    };
  });

  const edges = json.nodes
    .filter((n) => n.parent)
    .map((n) => ({
      id: `${n.parent}-${n.id}`,
      source: n.parent,
      target: n.id,
      animated: true
    }));

  return { nodes, edges };
}

function FlowDiagram({ diagramJson }) {
  const { nodes, edges } = parseJsonToElements(diagramJson);

  return (
    <div className="w-full h-[600px]">
      <ReactFlowProvider>
        <ReactFlow
          nodes={nodes}
          edges={edges}
          nodeTypes={nodeTypes}
          fitView
        >
          <MiniMap />
          <Controls />
          <Background />
        </ReactFlow>
      </ReactFlowProvider>
    </div>
  );
}

export default function App() {
  const [jsonText, setJsonText] = useState('');
  const [parsedJson, setParsedJson] = useState(null);

  const handleGenerate = useCallback(() => {
    try {
      const json = JSON.parse(jsonText);
      setParsedJson(json);
    } catch (err) {
      alert('Invalid JSON');
    }
  }, [jsonText]);

  return (
    <div className="p-4 space-y-4">
      <textarea
        className="w-full h-48 p-2 border rounded"
        placeholder="Paste JSON here..."
        value={jsonText}
        onChange={(e) => setJsonText(e.target.value)}
      />
      <button
        onClick={handleGenerate}
        className="px-4 py-2 bg-blue-600 text-white rounded"
      >
        Generate Diagram
      </button>
      {parsedJson && <FlowDiagram diagramJson={parsedJson} />}
    </div>
  );
}
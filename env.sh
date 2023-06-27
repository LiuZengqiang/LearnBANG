#!/usr/bin/bash
if [[ -z ${NEUWARE_HOME} ]]; then
  export NEUWARE_HOME=/usr/local/neuware
  echo "set env 'NEUWARE_HOME' to default: ${NEUWARE_HOME}."
else
  echo "env 'NEUWRAE_HOME': ${NEUWARE_HOME}."
fi

export PATH=${NEUWARE_HOME}/bin:${PATH}
export LD_LIBRARY_PATH=${NEUWARE_HOME}/lib64:${LD_LIBRARY_PATH}

echo "Ready for mlu-ops-building."

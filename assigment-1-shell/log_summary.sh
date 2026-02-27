#!/usr/bin/env bash
if [ $# -ne 1 ]; then
  echo "Usage: $0 <logfile>" >&2
  exit 1
fi

file="$1"

if [ ! -f "$file" ]; then
  echo "File not found: $file" >&2
  exit 2
fi

lines=$(wc -l < "$file")
echo "LINES: $lines"
echo "STATUS_COUNTS:"
cut -d' ' -f2 "$file" | sort | uniq -c | sort -rn | awk '{print $2" "$1}'
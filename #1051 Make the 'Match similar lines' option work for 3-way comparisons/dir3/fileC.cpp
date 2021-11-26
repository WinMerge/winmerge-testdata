				int result = strdiff::Compare(str[0], str[1],
					!diffOptions.bIgnoreCase,
					!diffOptions.bIgnoreEol,
					diffOptions.nIgnoreWhitespace,
					diffOptions.bIgnoreNumbers);
				if (m_nBuffers >= 2 && result == 0)
				{
					result = strdiff::Compare(str[1], str[2],
						!diffOptions.bIgnoreCase,
						!diffOptions.bIgnoreEol,
						diffOptions.nIgnoreWhitespace,
						diffOptions.bIgnoreNumbers);
				}
				if (result != 0)
				{
					for (int file = 0; file < m_nBuffers; ++file)
						m_ptBuf[file]->SetLineFlag(i, LF_TRIVIAL, true, false, false);
					++m_nTrivialDiffs;
				}

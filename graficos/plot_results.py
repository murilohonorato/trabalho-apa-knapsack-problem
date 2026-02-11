import pandas as pd
import matplotlib.pyplot as plt
import io
import re
import os

def parse_md_table(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()
    
    # Encontrar as linhas da tabela
    table_lines = [l for l in lines if '|' in l and '-' * 3 not in l]
    if not table_lines:
        return None
    
    # Cabeçalho e dados
    headers = [h.strip() for h in table_lines[0].split('|') if h.strip()]
    data = []
    
    for line in table_lines[1:]:
        cols = [c.strip() for c in line.split('|') if c.strip() != '']
        if len(cols) >= 5:
            # Limpeza dos dados
            # N (Itens) - remover pontos
            n_str = cols[0].replace('.', '')
            try:
                n = int(n_str)
            except ValueError:
                continue
                
            # Funções de limpeza para os tempos
            def clean_time(t_str):
                if not t_str or t_str == '-' or '*' in t_str:
                    return None
                t_str = t_str.replace('s', '').strip()
                try:
                    return float(t_str)
                except ValueError:
                    return None

            t_frac = clean_time(cols[2])
            t_bin_rec = clean_time(cols[3])
            t_bin_dp = clean_time(cols[4])
            
            data.append([n, t_frac, t_bin_rec, t_bin_dp])
            
    df = pd.DataFrame(data, columns=['N', 'Fracionária', 'Binária_Rec', 'Binária_DP'])
    return df

def plot_comparison(df, output_path):
    plt.figure(figsize=(10, 6))
    
    # Filtrar dados válidos para Fracionária e DP
    df_plot = df.dropna(subset=['Fracionária', 'Binária_DP'])
    
    plt.plot(df_plot['N'], df_plot['Fracionária'], marker='o', label='Mochila Fracionária (Gulosa)', color='#1f77b4', linewidth=2)
    plt.plot(df_plot['N'], df_plot['Binária_DP'], marker='s', label='Mochila Binária (Programação Dinâmica)', color='#ff7f0e', linewidth=2)
    
    plt.title('Comparativo de Tempo: Mochila Fracionária vs Binária (DP)', fontsize=14, fontweight='bold', pad=20)
    plt.xlabel('Número de Itens (N)', fontsize=12)
    plt.ylabel('Tempo de Execução (segundos)', fontsize=12)
    
    plt.xscale('log')
    plt.yscale('log')
    plt.grid(True, which="both", ls="-", alpha=0.3)
    plt.legend(fontsize=10)
    
    plt.tight_layout()
    plt.savefig(output_path, dpi=300)
    print(f"Gráfico salvo em: {output_path}")

def plot_recursive_explosion(df, output_path):
    plt.figure(figsize=(10, 6))
    
    # Dados da recursiva (geralmente apenas N pequenos)
    df_rec = df.dropna(subset=['Binária_Rec'])
    
    if df_rec.empty:
        print("Sem dados suficientes para a Binária Recursiva")
        return

    plt.plot(df_rec['N'], df_rec['Binária_Rec'], marker='d', color='#d62728', label='Mochila Binária (Recursiva)', linewidth=2)
    
    plt.title('Explosão Exponencial: Mochila Binária Recursiva', fontsize=14, fontweight='bold', pad=20)
    plt.xlabel('Número de Itens (N)', fontsize=12)
    plt.ylabel('Tempo de Execução (segundos)', fontsize=12)
    plt.grid(True, alpha=0.3)
    plt.legend(fontsize=10)
    
    # Adicionar anotação sobre a complexidade
    plt.annotate('Crescimento Exponencial O(2^n)', 
                 xy=(df_rec['N'].iloc[-1], df_rec['Binária_Rec'].iloc[-1]), 
                 xytext=(df_rec['N'].iloc[-1]-10, df_rec['Binária_Rec'].iloc[-1]+0.5),
                 arrowprops=dict(facecolor='black', shrink=0.05, width=1, headwidth=5),
                 fontsize=10)

    plt.tight_layout()
    plt.savefig(output_path, dpi=300)
    print(f"Gráfico salvo em: {output_path}")

def plot_greedy_efficiency(df, output_path):
    plt.figure(figsize=(10, 6))
    
    # Apenas fracionária, em escala linear para mostrar a eficiência
    df_frac = df.dropna(subset=['Fracionária'])
    
    plt.plot(df_frac['N'], df_frac['Fracionária'], marker='o', color='#2ca02c', label='Tempo Mochila Fracionária')
    
    plt.title('Eficiência da Abordagem Gulosa (Fracionária)', fontsize=14, fontweight='bold', pad=20)
    plt.xlabel('Número de Itens (N)', fontsize=12)
    plt.ylabel('Tempo de Execução (segundos)', fontsize=12)
    plt.grid(True, alpha=0.3)
    
    # Formatação do eixo X para não mostrar notação científica feia
    plt.ticklabel_format(style='plain', axis='x')
    
    plt.tight_layout()
    plt.savefig(output_path, dpi=300)
    print(f"Gráfico salvo em: {output_path}")

def plot_fractional_focus(df, output_path):
    plt.figure(figsize=(10, 6))
    df_frac = df.dropna(subset=['Fracionária'])
    
    # Plot com área sombreada para estética premium
    plt.fill_between(df_frac['N'], df_frac['Fracionária'], color='#1f77b4', alpha=0.1)
    plt.plot(df_frac['N'], df_frac['Fracionária'], marker='o', color='#1f77b4', linewidth=2.5, label='Tempo de Execução (Guloso)')
    
    plt.title('Performance do Algoritmo Principal: Mochila Fracionária', fontsize=15, fontweight='bold', color='#123456')
    plt.xlabel('Número de Itens (N)', fontsize=12)
    plt.ylabel('Tempo em Segundos', fontsize=12)
    
    plt.xscale('log')
    plt.grid(True, which="both", ls="-", alpha=0.2)
    plt.legend()
    
    # Anotação de eficiência
    plt.annotate('Eficiência O(n log n)', xy=(df_frac['N'].iloc[-1], df_frac['Fracionária'].iloc[-1]), 
                 xytext=(df_frac['N'].iloc[-1]/100, df_frac['Fracionária'].iloc[-1]*1.5),
                 arrowprops=dict(facecolor='black', shrink=0.05, width=1))

    plt.tight_layout()
    plt.savefig(output_path, dpi=300)
    print(f"Gráfico de foco salvo em: {output_path}")

if __name__ == "__main__":
    report_path = "performance_report.md"
    if not os.path.exists(report_path):
        # Tentar caminho relativo ao repositório se estiver rodando de outro lugar
        report_path = os.path.join(os.getcwd(), "graficos", "performance_report.md")
        os.chdir(os.path.dirname(report_path))
        report_path = "performance_report.md"

    df = parse_md_table(report_path)
    
    if df is not None:
        plot_fractional_focus(df, "foco_fracionaria.png")
        plot_comparison(df, "comparativo_geral.png")
        plot_recursive_explosion(df, "explosao_recursiva.png")
        plot_greedy_efficiency(df, "eficiencia_fracionaria.png")
    else:
        print("Erro ao processar a tabela do relatório.")
